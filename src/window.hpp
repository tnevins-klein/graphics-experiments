#include <SDL3/SDL.h>

class Window {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        Window(char* name, int width, int height);
        ~Window();

        SDL_Renderer* getRenderer();
};