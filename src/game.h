#define SDL_MAIN_HANDLED

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

//Function declarations
bool init(SDL_Window** window);
bool loadMedia(SDL_Window* window);
void close(SDL_Window* window);

#endif
