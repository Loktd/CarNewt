#include <Graphics/Vertex/OneColorVertexHandler2D.h>

void OneColorVertexHandler2D::UpdateGPU()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_Points.size() * sizeof(SingleColorVertex2D), std::addressof(m_Points[0]), GL_DYNAMIC_DRAW);
}

void OneColorVertexHandler2D::Add(const Vertex2D& vertex)
{
    m_Points.emplace_back(vertex.m_Position);
}

void OneColorVertexHandler2D::DoDrawing(const GLenum& mode)
{
    glDrawArrays(mode, 0, m_Points.size());
}

OneColorVertexHandler2D::OneColorVertexHandler2D(const glm::vec4& color)
    : m_Color(color)
{
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, sizeof(glm::vec2) / sizeof(float), GL_FLOAT, GL_FALSE, sizeof(SingleColorVertex2D), (void*)offsetof(SingleColorVertex2D, m_Position));
}

void OneColorVertexHandler2D::SetUniforms(std::shared_ptr<Shader2D> shader)
{
    shader->SetFlags(false, false);
    shader->SetUniformColor(m_Color);
}

void VertexHandler2D::Bind()
{
    glBindVertexArray(m_VAO);
}
