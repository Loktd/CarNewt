#include <Graphics/Camera2D.h>

Camera2D::Camera2D(const glm::vec2& wPosition, const glm::vec2& wSize)
    : m_CenterInWorld(wPosition), m_SizeInWorld(wSize)
{
}

glm::mat4 Camera2D::ViewTransform()
{
    return MatrixCreator::Translate(glm::vec3(-m_CenterInWorld.x, -m_CenterInWorld.y, 0));
}

glm::mat4 Camera2D::InverseViewTransform()
{
    return MatrixCreator::Translate(glm::vec3(m_CenterInWorld.x, m_CenterInWorld.y, 0));
}

glm::mat4 Camera2D::ProjectionTransform()
{
    return MatrixCreator::Scale(glm::vec3(2 / m_SizeInWorld.x, 2 / m_SizeInWorld.y, 1));
}

glm::mat4 Camera2D::InverseProjectionTransform()
{
    return MatrixCreator::Scale(glm::vec3(m_SizeInWorld.x / 2, m_SizeInWorld.y / 2, 1));
}

void Camera2D::Zoom(float s)
{
    m_SizeInWorld *= s;
}

void Camera2D::Pan(const glm::vec2& by)
{
    m_CenterInWorld += by;
}
