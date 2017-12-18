#pragma once

#include <glm/vec3.hpp>

class Transform {
private:
    glm::vec3   position,
                rotation,
                scale;
public:
    inline glm::vec3 getPos() const {
        return position;
    }
    inline glm::vec3 getRot() const {
        return rotation;
    }
    inline glm::vec3 getScale() const {
        return scale;
    }

    inline void setPos(const glm::vec3 &pos) {
        position = pos;
    }
    inline void setRot(const glm::vec3 &rot) {
        rotation = rot;
    }
    inline void setScale(const glm::vec3 &scl) {
        scale = scl;
    }
};

class Object {
protected:
    Transform transform;
public:
    virtual ~Object()=default;
};