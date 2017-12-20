#pragma once

#include <cstdint>

enum STRIDE{
    RGB8 = 1,
    RGB888 = 3,
};

struct rgb888_t {
    uint8_t r, g, b;
    rgb888_t() : r(0), g(0), b(0){};
    rgb888_t(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b){};
};

typedef rgb888_t Color; // TODO: change this for a less generalized name!


class Image {
private:
    unsigned int width, height;
    unsigned int stride;
    unsigned char* data; // image data byte array

    bool initData();

public:
    Image();
    Image(unsigned int width, unsigned int height);

    inline unsigned int getWidth() const {
        return width;
    }
    inline unsigned int getHeight() const {
        return height;
    }

    inline Color getPixel(unsigned int x, unsigned int y) const {
        Color c;
        unsigned int idx = stride*(y * width + x);
        c.r = static_cast<uint8_t>(data[idx]);
        c.g = static_cast<uint8_t>(data[idx + 1]);
        c.b = static_cast<uint8_t>(data[idx + 2]);
        return c;
    }

    inline void setPixel(unsigned int x, unsigned int y, Color c) const {
        unsigned int idx = stride*(y * width + x);
        data[idx] = c.r;
        data[idx + 1] = c.g;
        data[idx + 2] = c.b;
    }

    void saveData(const char* file) const;

    virtual ~Image()=default;
};