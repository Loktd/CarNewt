#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glad/gl.h>

#include <Graphics/Object2D.h>
#include <Graphics/OneColorVertexHandler2D.h>

class SimpleShape : public Object2D
{
protected:
    glm::vec2 m_WorldCenter;
    float m_Rotation;
    glm::vec2 m_Scale;

    GLenum VertexDrawMode() override;
    glm::mat4 ModelTransform() override;
public:
    SimpleShape(const SingleColorVertex2D& center, const glm::vec4& color, float rotation = 0, const glm::vec2& scale = glm::vec2(1, 1));
    // SimpleShape(const TexturedVertex2D& center, float rotation = 0, const glm::vec2& scale = glm::vec2(1, 1));
    // SimpleShape(const MultiColorVertex2D& center, float rotation = 0, const glm::vec2& scale = glm::vec2(1, 1));
    virtual ~SimpleShape();
};