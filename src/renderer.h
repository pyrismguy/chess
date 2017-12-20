#pragma once

#include "scene.h"
#include "ray.h"
#include "shapes/shape.h"
#include "image.h"

class Renderer {
private:
    static Renderer *sInstance;

    Renderer()=default;
    virtual ~Renderer()=default;

    Intersection traceScene(const Ray& ray, std::vector<Shape*> shapes) const;
    float trace(const Ray &r, const Shape &shape) const;

public:
    static Renderer* getInstance() {
        if (!sInstance) {
             sInstance = new Renderer();
        }
        return sInstance;
    }

    //void loadScene(const Scene &scene);
    void render(const Image &img, const Scene &scene) const;
};