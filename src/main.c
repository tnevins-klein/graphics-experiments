#include <stdbool.h>
#include <stdio.h>

#include <SDL3/SDL.h>
 
int main(int argc, char *argv[])
{
 
    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME",
                                       640, 400, 0);
 
    printf("Found %d render drivers: \n", SDL_GetNumRenderDrivers());
    for (int i = 0; i < SDL_GetNumRenderDrivers(); i++) {
        printf("\t%s\n", SDL_GetRenderDriver(i));
    }

    uint32_t render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, NULL, SDL_RENDERER_SOFTWARE);

    if (rend == NULL) {
        printf("[ERR] Could not create renderer: %s\n", SDL_GetError());
        goto err;
    }

    bool close = false;

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
        SDL_RenderPresent(rend);

        SDL_Delay(1000 / 60);
    }

    err:
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();

    printf("[INFO] Done!\n");

    return 0;
}