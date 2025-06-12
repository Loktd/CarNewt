#pragma once

#include <vector>

#include <Graphics/VertexHandler2D.h>
#include <Graphics/Vertex2D.hpp>
#include <Graphics/Shader2D.h>

class OneColorVertexHandler2D : public VertexHandler2D
{
private:
    std::vector<SingleColorVertex2D> m_Points;
    glm::vec4 m_Color;

    void UpdateGPU() override;
    void Add(const Vertex2D& vertex) override;
    void DoDrawing(const GLenum& mode) override;
public:
    OneColorVertexHandler2D(const glm::vec4& color);
    void SetUniforms(std::shared_ptr<Shader2D> shader) override;
};
