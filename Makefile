CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
BIN_DIR = bin
LIB_NAME = estat
INCLUDE_DIR = include
TEST_DIR = tests
APP_DIR = app

STATIC_LIB = $(LIB_DIR)/lib$(LIB_NAME).a
SHARED_LIB = $(LIB_DIR)/lib$(LIB_NAME).so

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
PIC_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/pic/%.o,$(SRCS))
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)
TESTS = $(wildcard $(TEST_DIR)/test_*.c)
TEST_BINS = $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/%,$(TESTS))
TEST_DYN_BINS = $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/dyn_%,$(TESTS))

all: $(LIB_DIR)/lib$(LIB_NAME).a $(LIB_DIR)/lib$(LIB_NAME).so

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(wildcard $(INCLUDE_DIR)/*.h)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_DIR)/lib$(LIB_NAME).a: $(OBJS)
	mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(BUILD_DIR)/pic/%.o: $(SRC_DIR)/%.c $(wildcard $(INCLUDE_DIR)/*.h)
	mkdir -p $(BUILD_DIR)/pic
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(LIB_DIR)/lib$(LIB_NAME).so: $(PIC_OBJS)
	mkdir -p $(LIB_DIR)
	$(CC) -shared $^ -o $@ -lm

$(BIN_DIR)/test_%: $(TEST_DIR)/test_%.c $(LIB_DIR)/lib$(LIB_NAME).a
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIB_DIR)/lib$(LIB_NAME).a -o $@ -lm

$(BIN_DIR)/dyn_test_%: $(TEST_DIR)/test_%.c $(SHARED_LIB)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) -o $@ -lm

$(BIN_DIR)/app: $(APP_DIR)/main.c $(STATIC_LIB)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(STATIC_LIB) -o $@ -lm

$(BIN_DIR)/app_dyn: $(APP_DIR)/main.c $(SHARED_LIB)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) -o $@ -lm

test: $(TEST_BINS)
	@for t in $(TEST_BINS); do echo "== $$t"; ./$$t || exit 1; done

test-dyn: $(TEST_DYN_BINS)
	@for t in $(TEST_DYN_BINS); do echo "== $$t (dinamico)"; LD_LIBRARY_PATH=$(LIB_DIR) ./$$t || exit 1; done

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/pic/*.o $(LIB_DIR)/*.a $(LIB_DIR)/*.so $(BIN_DIR)/test_*
	rm -f $(BIN_DIR)/test_* $(BIN_DIR)/dyn_test_* $(BIN_DIR)/app $(BIN_DIR)/app_dyn

app: $(BIN_DIR)/app

app-dyn: $(BIN_DIR)/app_dyn

.PHONY: all clean test test-dyn app app-dyn
