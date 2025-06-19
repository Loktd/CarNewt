#pragma once

#include <glm/glm.hpp>
#include <glad/gl.h>
#include <vector>

#include <Graphics/Generics/IDrawable2D.h>
#include <Graphics/Vertex/VertexHandler2D.h>

class Object2D : public IDrawable2D
{
protected:
    std::unique_ptr<VertexHandler2D> m_VertexHandler;

    virtual GLenum VertexDrawMode() = 0;
    virtual glm::mat4 ModelTransform() = 0;
public:
    void Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) override;
    virtual ~Object2D();
};
