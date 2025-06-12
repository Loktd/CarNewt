#pragma once

#include <glad/gl.h>

#include <Graphics/MatrixCreator.h>

class Camera2D
{
private:
    glm::vec2 m_CenterInWorld;
    glm::vec2 m_SizeInWorld;
public:
    Camera2D(const glm::vec2& wPosition, const glm::vec2& wSize);
    glm::mat4 ViewTransform();
    glm::mat4 InverseViewTransform();
    glm::mat4 ProjectionTransform();
    glm::mat4 InverseProjectionTransform();
    void Zoom(float s);
    void Pan(const glm::vec2& by);
};
