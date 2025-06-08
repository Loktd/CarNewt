#include <Scene/MainMenuScene.h>

#include <GLFW/glfw3.h>

#include <Engine/WindowingEngine.h>

MainMenuScene::MainMenuScene() : SceneBase(glm::vec4(1, 0, 0, 1)) {}

void MainMenuScene::HandleKeyPressed(int key) {
    if (key == GLFW_KEY_S) {
        WindowingEngine::GetInstance().SwitchToScene(SceneName::SIMULATION);
    }
}
