# Dynamic Renderer Issue

I have experienced an issue where when called from a dynamic library, SDL_GL_GetProcAddress results in a segfault. This is probably bug on my side, either in the code, or in the build process, but I was unable to figure it out on my own, so I created this repository containing a minimal example that fails on my computers, so that someone might be able to help.
Interestingly, this code runs on my mac (or something similar. The minimal example is not tested on my mac, but the much more complex real world case is, and works fine on macOS).

