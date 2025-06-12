#include <Scene/SimulationScene.h>

SimulationScene::SimulationScene() : SceneBase(glm::vec4(0, 1, 0, 1)), m_Loader() {
    m_Camera = std::make_shared<Camera2D>(glm::vec2(0, 0), glm::vec2(800, 600));
    m_Shader = std::make_shared<Shader2D>();

    m_Shader->Use();
}

void SimulationScene::InitializeScene() {
    m_Loader.AskForDirectory();
    m_RoadNetwork = m_Loader.LoadRoadNetwork();
}

void SimulationScene::HandleKeyPressed(int key) {
    if (key == GLFW_KEY_ESCAPE) {
        WindowingEngine::GetInstance().Exit();
    }

    if (key == GLFW_KEY_E) {
        m_Camera->Zoom(0.9);
    }
    if (key == GLFW_KEY_Q) {
        m_Camera->Zoom(1.1);
    }

    if (key == GLFW_KEY_A) {
        m_Camera->Pan(glm::vec2(-10, 0));
    }
    if (key == GLFW_KEY_D) {
        m_Camera->Pan(glm::vec2(10, 0));
    }
    if (key == GLFW_KEY_W) {
        m_Camera->Pan(glm::vec2(0, 10));
    }
    if (key == GLFW_KEY_S) {
        m_Camera->Pan(glm::vec2(0, -10));
    }

    WindowingEngine::GetInstance().Refresh();
}

void SimulationScene::Render()
{
    SceneBase::Render();

    m_RoadNetwork->Draw(m_Shader, m_Camera);
}