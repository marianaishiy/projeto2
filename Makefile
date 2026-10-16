CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
BIN_DIR = bin
LIB_NAME = lib_estat
INCLUDE_DIR = include
TEST_DIR = tests

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
PIC_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/pic/%.o,$(SRCS))
TESTS = $(wildcard $(TEST_DIR)/test_*.c)
TEST_BINS = $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/%,$(TESTS))

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
test: $(TEST_BINS)
	@for t in $(TEST_BINS); do echo "== $$t"; ./$$t || exit 1; done

clean: 
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/pic/*.o $(LIB_DIR)/*.a $(LIB_DIR)/*.so $(BIN_DIR)/test_*

.PHONY: all clean test
