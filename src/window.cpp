#include "window.hpp"

Window::Window(char* name, int width, int height) {
    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    printf("Found %d render drivers: \n", SDL_GetNumRenderDrivers());
    for (int i = 0; i < SDL_GetNumRenderDrivers(); i++) {
        printf("\t%s\n", SDL_GetRenderDriver(i));
    }

    window = SDL_CreateWindow(name, width, height, 0);
    if (window == NULL) {
        printf("[ERR] Could not initialize window: %s", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, NULL, 0);
    if (renderer == NULL) {
        printf("[ERR] Could not create rendering context: %s", SDL_GetError());
        return;
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}
