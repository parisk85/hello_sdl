#include "game.h"
#include "constants.h"
#include <stdio.h>

SDL_Renderer* gRenderer = NULL;

int main(int argc, char* args[]) {
  // The window we'll be rendering to
  SDL_Window* window = NULL;

  // Initialize SDL
  if (!init(&window)) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Load media
  if (!loadMedia(window)) {
    printf("Failed to load media!\n");
    return 1;
  }

  // Hack to get window to stay up
  SDL_Event e;
  bool quit = false;
  Uint32 ticks;
  while (!quit) {
    ticks = SDL_GetTicks();

    //Handle input events
    handleInput(quit);

    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(gRenderer);

    // Render objects here

    // Update screen
    SDL_RenderPresent(gRenderer);

    // Limit frame rate
    Uint32 delta = SDL_GetTicks() - ticks;
    if (delta < constants::FRAME_DELAY) {
      SDL_Delay(constants::FRAME_DELAY - delta);
    }
  }

  // Close SDL
  close(window);

  return 0;
}

bool init(SDL_Window** window) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  // Create window
  *window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (*window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  // Create renderer
  gRenderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (gRenderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void handleInput(bool &quit) {
  //Handle events on queue
  SDL_Event e;
  while( SDL_PollEvent( &e ) != 0 ) {
    //User requests quit
    if( e.type == SDL_QUIT ) {
      quit = true;
    }
    //User presses escape key
    else if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE ) {
      quit = true;
    }
  }
}


bool loadMedia(SDL_Window* window) {
  // Load media here
  return true;
}

void close(SDL_Window* window) {
  // Destroy renderer
  SDL_DestroyRenderer(gRenderer);

  // Destroy window
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();
}
