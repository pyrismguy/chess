#include <cstdio>
#include <cstdlib>
#include "stb_image_write.h"

#include "image.h"

Image::Image() : width(640), height(480), stride(RGB888) {
    if (!initData()) {
        fprintf(stderr, "Error: %s\n", "Failed to initialize image data.");
        exit(1);
    }
}

Image::Image(unsigned int width, unsigned int height) : width(width), height(height), stride(RGB888) {
    if (!initData()) {
        fprintf(stderr, "Error: %s\n", "Failed to initialize image data.");
        exit(1);
    }
}

bool Image::initData() {
    data = static_cast<unsigned char*>(malloc(stride * width*height));
    return true;
}

void Image::saveData(const char *file) const {
    stbi_write_bmp(file, width, height, 3, data);
}
