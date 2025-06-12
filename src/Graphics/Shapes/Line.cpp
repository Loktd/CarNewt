#include <Graphics/Shapes/Line.h>

Line::Line(const glm::vec2& from, const glm::vec2& to, const glm::vec4& color, float width)
    : m_Origin(from), m_Width(width)
{
    m_VertexHandler = std::make_unique<OneColorVertexHandler2D>(color);
    m_VertexHandler->AddVertex(Vertex2D(glm::vec2(0, 0)));
    m_VertexHandler->AddVertex(Vertex2D(glm::vec2(1, 0)));

    glm::vec2 diff = to - from;
    m_Length = glm::length(diff);
    m_Angle = glm::atan(diff.y, diff.x);
}

GLenum Line::VertexDrawMode() {
    return GL_LINES;
}

glm::mat4 Line::ModelTransform() {
    return MatrixCreator::Translate(glm::vec3(m_Origin.x, m_Origin.y, 0)) * MatrixCreator::Rotate(m_Angle, glm::vec3(0, 0, 1)) * MatrixCreator::Scale(glm::vec3(m_Length, 1, 1));
}

void Line::Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) {    
    Object2D::Draw(shader, camera);
}

