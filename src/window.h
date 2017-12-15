#pragma once

class Window {
    int width, height;
public:
    Window(int width, int height);
    virtual ~Window();

    void refresh();

    inline int getWidth() const { return width; }
    inline int getHeight() const { return height; }
};