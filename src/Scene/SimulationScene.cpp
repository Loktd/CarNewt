#include <Scene/SimulationScene.h>
#include <GLFW/glfw3.h>
#include <Engine/WindowingEngine.h>

SimulationScene::SimulationScene() : SceneBase(glm::vec4(0, 1, 0, 1))
{
}

void SimulationScene::HandleKeyPressed(int key) {
    if (key == GLFW_KEY_ESCAPE) {
        WindowingEngine::GetInstance().Exit();
    }
}