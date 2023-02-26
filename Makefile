#OBJS specifies which files to compile as part of the project
OBJS = src/game.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	g++ -std=c++11 -Isrc/ -Iinclude/ -Ilib/SDL2/include/ src/*.cpp -Llib/SDL2/ -Wl,-rpath,./lib/SDL2/ -lSDL2 -o bin/game

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: clean
