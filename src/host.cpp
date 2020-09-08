#include <SDL.h>

#define LIB_NAME "libRenderer.so"

int main(int num_args, char *args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    printf("Attempting to load library %s..\n", LIB_NAME);

    void *lib_handle = SDL_LoadObject(LIB_NAME);
    SDL_assert(lib_handle);

    void *init_func =  SDL_LoadFunction(lib_handle, "renderer_init");
    SDL_assert(init_func);

    void *clear_func =  SDL_LoadFunction(lib_handle, "renderer_new_frame");
    SDL_assert(clear_func);

    puts("Success");

    puts("Initializing renderer");
    ((void (*)(void))init_func)();

    bool running = true;
    while(running)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                running = false;
            }
        }


        ((void (*)(void))clear_func)();
    }

    SDL_Quit();

    return 0;
}

