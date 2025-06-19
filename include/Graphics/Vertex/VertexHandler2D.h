#pragma once

#include <memory>

#include <Graphics/Shaders/Shader2D.h>
#include <Graphics/Camera/Camera2D.h>
#include <Graphics/Vertex/Vertex2D.hpp>

class VertexHandler2D
{
protected:
    GLuint m_VAO, m_VBO;
    bool m_UpdateNeeded;

    void Bind();
    virtual void UpdateGPU() = 0;
    virtual void Add(const Vertex2D& vertex) = 0;
    virtual void DoDrawing(const GLenum& mode) = 0;
public:
    VertexHandler2D();
    void Draw(const GLenum& mode);
    void AddVertex(const Vertex2D& vertex);
    virtual void SetUniforms(std::shared_ptr<Shader2D> shader) = 0;
    virtual ~VertexHandler2D();
};
