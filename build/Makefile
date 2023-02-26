SRC_DIR := src/
INCLUDE_DIR := include/
LIB_DIR := lib/SDL2/
BIN_DIR := bin/
OBJ_NAME := game

OBJS := $(wildcard $(SRC_DIR)*.cpp)
INC := -I$(SRC_DIR) -I$(INCLUDE_DIR) -I$(LIB_DIR)include/SDL2
LIB := -L$(LIB_DIR) -Wl,-rpath,$(LIB_DIR) -lSDL2
CFLAGS := -std=c++11 $(INC)

all: $(BIN_DIR)$(OBJ_NAME)

$(BIN_DIR)$(OBJ_NAME): $(OBJS)
	g++ $(CFLAGS) $^ $(LIB) -o $@

$(SRC_DIR)%.o: $(SRC_DIR)%.cpp
	g++ $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(BIN_DIR)$(OBJ_NAME)

.PHONY: clean
