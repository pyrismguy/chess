#pragma once
#include <SDL.h>
#include <SDL_video.h>

class Window {
    const char* title;
    int width, height;
    SDL_Window *window;
    SDL_GLContext context;
    bool closed;
public:
    Window(const char* title, int width, int height);
    virtual ~Window();

    void refresh();

    inline int getWidth() const {
        return width;
    }
    inline int getHeight() const {
        return height;
    }

    inline bool isClosed() const {
        return closed;
    }
    inline void close() {
        closed = true;
    }
};