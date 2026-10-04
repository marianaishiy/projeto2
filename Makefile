CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
BIN_DIR = bin
LIB_NAME = lib_estat
INCLUDE_DIR = include

all: $(LIB_DIR)/lib$(LIB_NAME).a $(LIB_DIR)/lib$(LIB_NAME).so
	
$(BUILD_DIR)/esperanca.o: $(SRC_DIR)/esperanca.c $(INCLUDE_DIR)/esperanca.h $(INCLUDE_DIR)/erros.h
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_DIR)/lib$(LIB_NAME).a: $(BUILD_DIR)/esperanca.o
	mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(BUILD_DIR)/pic/esperanca.o: $(SRC_DIR)/esperanca.c $(INCLUDE_DIR)/esperanca.h $(INCLUDE_DIR)/erros.h
	mkdir -p $(BUILD_DIR)/pic 
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(LIB_DIR)/lib$(LIB_NAME).so: $(BUILD_DIR)/pic/esperanca.o
	mkdir -p $(LIB_DIR)
	$(CC) -shared $^ -o $@

clean: 
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/pic/*.o $(LIB_DIR)/*.a $(LIB_DIR)/*.so

.PHONY: all clean
