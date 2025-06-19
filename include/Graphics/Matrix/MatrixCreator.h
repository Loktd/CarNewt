#pragma once

#include <glm/glm.hpp>

namespace MatrixCreator {
    glm::mat4 Translate(const glm::vec3& by);

    glm::mat4 Scale(const glm::vec3& factor);

    glm::mat4 Rotate(float angle, const glm::vec3& around);
}