#include <stdbool.h>
#include <stdio.h>

#include<complex>

#include <SDL3/SDL.h>
#include "window.hpp"

#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH  640

int main(int argc, char *argv[])
{
    Window window("Mandelbrot Set", SCREEN_HEIGHT, SCREEN_WIDTH);
    SDL_Renderer* rend = window.getRenderer();

    bool close = false;

    int color = 0;

    SDL_Surface* silly = SDL_LoadBMP("gfx/silly.bmp");
    if (silly == NULL) {
        printf("Couldn't load image: %s", SDL_GetError());
    }
    
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, silly);

    int x = 0;
    int y = 0;
    while (!close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    close = true;
                    break;
            }
        }
        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
        SDL_RenderClear(rend);

        SDL_FRect r = {
            .x = x,
            .y = y,
            .h = 300,
            .w = 300
        };
        SDL_RenderTexture(rend, tex, NULL, &r);

        SDL_RenderPresent(rend);
    }

    SDL_DestroySurface(silly);
    SDL_DestroyTexture(tex);

    return 0;
}