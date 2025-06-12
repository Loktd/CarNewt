#pragma once

#include <Graphics/Object2D.h>
#include <Graphics/OneColorVertexHandler2D.h>

class Line : public Object2D
{
protected:
    glm::vec2 m_Origin;
    float m_Length;
    float m_Angle;
    float m_Width;

    GLenum VertexDrawMode() override;
    glm::mat4 ModelTransform() override;
public:
    Line(const glm::vec2& from, const glm::vec2& to, const glm::vec4& color, float width);
    void Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) override;
};