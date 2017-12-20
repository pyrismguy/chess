#pragma once

#include <glm/vec3.hpp>

class Transform {
private:
    glm::vec3   position,
                rotation,
                scale;
public:
    Transform();
    Transform(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scl);

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

