#include "transform.h"

Transform::Transform() :
        position(glm::vec3(0.0f, 0.0f, 0.0f)),
        rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
        scale(glm::vec3(1.0f, 1.0f, 1.0f))
{

}

Transform::Transform(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scl) :
    position(pos),
    rotation(rot),
    scale(scl)
{

}
