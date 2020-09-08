#include "gl.h"

#define GLE(ret, name, ...) name##proc * gl##name;
ISTARI_GL_FUNCS
#undef GLE

void
load_gl_functions()
{
#define GLE(ret, name, ...) do {\
    printf("Loading %s...\n", "gl"#name);\
    gl##name = (name##proc *) SDL_GL_GetProcAddress("gl"#name);\
    SDL_assert(gl##name);\
} while(0);
    ISTARI_GL_FUNCS
#undef GLE
}

