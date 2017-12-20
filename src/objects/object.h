#pragma once

#include "transform.h"

class Object {
protected:
    Transform transform;
public:
    Object(const Transform &t);
    virtual ~Object()=default;
};
