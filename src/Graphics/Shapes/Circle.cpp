#include <Graphics/Shapes/Circle.h>

Circle::Circle(const glm::vec2& center, float radius, const glm::vec4& color)
    : SimpleShape(SingleColorVertex2D(center), color, 0, glm::vec2(radius, radius))
{
    for (size_t i = 0; i <= BORDER_POINTS; i++) {
        double angle = (2 * M_PI / (BORDER_POINTS)) * i;
        glm::vec2 point(glm::cos(angle), glm::sin(angle));
        m_VertexHandler->AddVertex(Vertex2D(point));
    }
}