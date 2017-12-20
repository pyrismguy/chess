#include "renderer.h"
#include "shapes/shape.h"

Renderer* Renderer::sInstance = nullptr;

void Renderer::render(const Image &img, const Scene &scene) const {

    PerspectiveCamera* camera = scene.getMainCamera();
    camera->setAspect(static_cast<float>(img.getWidth())/ static_cast<float>(img.getHeight()));

    for (unsigned int y = 0; y < img.getHeight(); ++y) {
        for (unsigned int x = 0; x < img.getWidth(); ++x) {
            glm::vec2 uv = glm::vec2((2.0f*x) / img.getWidth() - 1.0f, (-2.0f*y) / img.getHeight() + 1.0f);

            Intersection intersection = traceScene(camera->makeRay(uv), scene.getShapes());

            glm::vec3 normal = intersection.pShape->normal(intersection.position());

            auto r = static_cast<uint8_t>((normal.x*128.0f)+128.0f);
            auto g = static_cast<uint8_t>((normal.y*128.0f)+128.0f);
            auto b = static_cast<uint8_t>((normal.z*128.0f)+128.0f);

            auto z = static_cast<uint8_t>((1.0f/intersection.t)*256);

            Color c = Color(r, g, b);

            img.setPixel(x, y, c);
        }
    }
}


/*
 * All of this is extremely nasty! TODO: CHANGE THIS QUICK!!!
 */

#define MAX_ITERATIONS 128


Intersection Renderer::traceScene(const Ray &ray, const std::vector<Shape*> shapes) const {
    Intersection intr = Intersection(ray);
    intr.t = trace(intr.ray, *shapes.at(0));
    intr.pShape = shapes.at(0);

    for (unsigned int i = 1; i < shapes.size(); ++i) {
        float t = trace(intr.ray, *shapes.at(i));
        if (t < intr.t) {
            intr.pShape = shapes.at(i);
            intr.t = t;
        }
    }

    return intr;
}

float Renderer::trace(const Ray &ray, const Shape& shape) const {
    float t = RAY_T_MIN;
    int i = 0;
    while (i < MAX_ITERATIONS && t < ray.tMax) {
        float radius = shape.distance(ray.calculate(t));
        if (radius < 0.001f)
            break;
        t += radius;
        i++;
    }
    if (i == MAX_ITERATIONS || t > ray.tMax)
        return RAY_T_MAX;
    return t;
}
