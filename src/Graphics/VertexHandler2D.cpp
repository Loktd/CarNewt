#include <Graphics/VertexHandler2D.h>

VertexHandler2D::VertexHandler2D()
{
    glGenVertexArrays(1, std::addressof(m_VAO));
    glBindVertexArray(m_VAO);
    glGenBuffers(1, std::addressof(m_VBO));
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}

void VertexHandler2D::Draw(const GLenum& mode)
{
    Bind();

    if (m_UpdateNeeded) {
        UpdateGPU();
        m_UpdateNeeded = false;
    }

    DoDrawing(mode);
}

void VertexHandler2D::AddVertex(const Vertex2D& vertex)
{
    Add(vertex);
    m_UpdateNeeded = true;
}

VertexHandler2D::~VertexHandler2D()
{
    glDeleteBuffers(1, std::addressof(m_VBO));
    glDeleteVertexArrays(1, std::addressof(m_VAO));
}