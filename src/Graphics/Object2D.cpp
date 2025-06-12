#include <Graphics/Object2D.h>

void Object2D::Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera)
{
    glm::mat4 MVP = camera->ProjectionTransform() * camera->ViewTransform() * ModelTransform();

    shader->SetMVP(MVP);
    m_VertexHandler->SetUniforms(shader);

    m_VertexHandler->Draw(VertexDrawMode());
}

Object2D::~Object2D() {}
