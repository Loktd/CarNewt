#include <Scene/SceneBase.h>

SceneBase::SceneBase(const glm::vec4& color) : m_Color(color) {}

void SceneBase::InitializeScene()
{
}

void SceneBase::HandleKeyPressed(int key)
{
}

void SceneBase::HandleKeyReleased(int key)
{
}

void SceneBase::HandleMousePressed(int button, int pX, int pY)
{
}

void SceneBase::HandleMouseReleased(int button, int pX, int pY)
{
}

void SceneBase::HandleMouseMotion(int pX, int pY)
{
}

void SceneBase::HandleTimeElapsed(double start, double end)
{
}

void SceneBase::Render()
{
    glClearColor(m_Color.r, m_Color.g, m_Color.b, m_Color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}
