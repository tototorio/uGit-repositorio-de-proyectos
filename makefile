CC=gcc
EXEC=ugit
GRUPO=G1
NTAR=2

SRC_DIR=src
OBJ_DIR=obj
BUILD_DIR=build
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
INCLUDE=-I./incs/
# LIBS=-lm

CFLAGS=-Wall -Wextra -Wpedantic -O3
# LDFLAGS=-Wall -lm

all: folders $(BUILD_DIR)/$(EXEC)

$(BUILD_DIR)/$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(INCLUDE) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

.PHONY: clean folders run

clean:
	rm -f $(OBJ_FILES)
	rm -f $(BUILD_DIR)/$(EXEC)

folders:
	mkdir -p $(SRC_DIR) $(OBJ_DIR) $(BUILD_DIR) incs docs

run: all
	@./$(BUILD_DIR)/$(EXEC)
