#pragma once

#include <vector>

#include "objects/object.h"
#include "shapes/shape.h"
#include "objects/camera.h"

#define NAME_LENGTH 25
#define DESC_LENGTH 255

class Scene
{
private:
    char *name, *desc;
    std::vector<Shape*> shapes;
    std::vector<Object*> objects;

    unsigned int mainCamIdx;

public:
    Scene(const char *file);
    virtual ~Scene();

    inline const char* getName() const {
        return name;
    }
    inline const char* getDescription() const {
        return desc;
    }
    PerspectiveCamera* getMainCamera() const {
        return static_cast<PerspectiveCamera*>(objects.at(mainCamIdx));
    }

    const std::vector<Shape*> getShapes() const {
        return shapes;
    }
};