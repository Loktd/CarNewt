#include <Scene/SimulationScene.h>

SimulationScene::SimulationScene() : SceneBase(glm::vec4(0, 1, 0, 1)), m_Loader() {}

void SimulationScene::InitializeScene() {
    m_Loader.AskForDirectory();
    m_RoadNetwork = m_Loader.LoadRoadNetwork();
}

void SimulationScene::HandleKeyPressed(int key) {
    if (key == GLFW_KEY_ESCAPE) {
        WindowingEngine::GetInstance().Exit();
    }
}