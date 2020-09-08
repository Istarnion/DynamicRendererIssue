#include <SDL.h>
#include "gl.cpp"

static SDL_Window *window;

extern "C" void
renderer_init(void)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    window = SDL_CreateWindow("Test <OpenGL 3.3>",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              400, 400,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_GLContext opengl = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, opengl);

    load_gl_functions();

    SDL_GL_SetSwapInterval(1);
}

extern "C" void
renderer_new_frame(void)
{
    SDL_GL_SwapWindow(window);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

