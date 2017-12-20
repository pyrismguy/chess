#include "window.h"
#include <cstdlib>

Window::Window(const char* title, int width, int height) : title(title), width(width), height(height)
{
    closed = false;
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

    window = SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );

    if (!window) {
        SDL_Log("Window creation failed: %s\n", SDL_GetError());
        exit(1);
    }
    context = SDL_GL_CreateContext(window);
}

Window::~Window()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::refresh()
{
    SDL_GL_SwapWindow(window);
}