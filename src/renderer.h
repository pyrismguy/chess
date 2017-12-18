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

    float trace(const Ray &r, const Shape &s) const;
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