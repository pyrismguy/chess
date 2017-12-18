#include "renderer.h"
#include "shapes/shape.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define MAX_ITERATIONS 128

Renderer* Renderer::sInstance = nullptr;

void Renderer::render(const Image &img, const Scene &scene) const {
    unsigned int width = img.getWidth(), height = img.getHeight();

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            Color c = img.getPixel(x, y);
            c.r = 255;
            img.setPixel(x, y, c);
        }
    }
}

float Renderer::trace(const Ray& r, const Shape& s) const {
    // o, d : ray origin, direction (normalized)
    // t_min, t_max: minimum, maximum t values

    float t = RAY_T_MIN;
    int i = 0;
    while (i < MAX_ITERATIONS && t < r.tMax) {
        float radius = s.getDistance(r.calculate(t));
        if (radius < 0.001f)
            break;
        t += radius;
        i++;
    }
    if (i == MAX_ITERATIONS || t > RAY_T_MAX)
        return RAY_T_MAX;
    return t;
}
