#pragma once

#include <glm/glm.hpp>

#include <Graphics/Shapes/SimpleShape.h>

class Circle : public SimpleShape
{
private:
    static const size_t BORDER_POINTS = 100;
public:
    Circle(const glm::vec2& center, float radius, const glm::vec4& color);
};
