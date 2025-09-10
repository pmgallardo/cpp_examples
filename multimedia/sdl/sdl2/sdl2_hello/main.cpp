// SDL2 Hello, World!

// COMPILATION INSTRUCTIONS
// Compile with:
// clang++ main.cpp -o hello_sdl2 -lSDL2
// 
// g++ main.cpp -o sdl2_hello -lSDL2
//
// or
//
// g++ main.cpp -o sdl2_hello -lSDL2main -lSDL2
//
// or
//
// (requires installation of package libsdl2-dev)
// g++ main.cpp -o sdl2_hello `sdl2-config --cflags --libs`

// EXECUTION INSTRUCTIONS
// Run with:
// ./hello_sdl2

// Uncomment in case of compiling error related to main function
//#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]) {
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }
  window = SDL_CreateWindow(
			    "hello_sdl2",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );
  if (window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }
  screenSurface = SDL_GetWindowSurface(window);
  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(window);
  SDL_Delay(2000);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}