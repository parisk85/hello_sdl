#include <stdio.h>
#include <game.h>
#include <constants.h>

int main( int argc, char* args[] ) {
  //The window we'll be rendering to
  SDL_Window* window = NULL;

  //Initialize SDL
  if( !init(&window) ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    return 1;
  }

  //Load media
  if( !loadMedia(window) ) {
    printf( "Failed to load media!\n" );
    return 1;
  }

  //Hack to get window to stay up
  SDL_Event e;
  bool quit = false;
  while( !quit ) {
    while( SDL_PollEvent( &e ) != 0 ) {
      if( e.type == SDL_QUIT ) {
        quit = true;
      }
    }
  }

  //Close SDL
  close(window);

  return 0;
}

bool init(SDL_Window** window) {
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    return false;
  }

  //Create window
  *window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if( *window == NULL ) {
    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    return false;
  }

  return true;
}

bool loadMedia(SDL_Window* window) {
  //Get window surface
  SDL_Surface* screenSurface = SDL_GetWindowSurface( window );

  //Fill the surface white
  SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

  //Update the surface
  SDL_UpdateWindowSurface( window );

  return true;
}

void close(SDL_Window* window) {
  //Destroy window
  SDL_DestroyWindow( window );

  //Quit SDL subsystems
  SDL_Quit();
}
