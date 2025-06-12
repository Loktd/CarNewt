#include <Graphics/Shapes/SimpleShape.h>

GLenum SimpleShape::VertexDrawMode()
{
    return GL_TRIANGLE_FAN;
}

glm::mat4 SimpleShape::ModelTransform()
{
    return MatrixCreator::Translate(glm::vec3(m_WorldCenter.x, m_WorldCenter.y, 0)) * MatrixCreator::Scale(glm::vec3(m_Scale.x, m_Scale.y, 1));
}

SimpleShape::SimpleShape(const SingleColorVertex2D& center, const glm::vec4& color, float rotation, const glm::vec2& scale)
    : m_WorldCenter(center.m_Position), m_Rotation(rotation), m_Scale(scale)
{
    m_VertexHandler = std::make_unique<OneColorVertexHandler2D>(color);
    m_VertexHandler->AddVertex(Vertex2D(glm::vec2(0, 0)));
}

SimpleShape::~SimpleShape()
{
}
