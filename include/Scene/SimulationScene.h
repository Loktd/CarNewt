#pragma once

#include <iostream>
#include <filesystem>

#include <Scene/SceneBase.h>
#include <Loader/NewtLoader.h>
#include <Engine/WindowingEngine.h>
#include <Graphics/Camera2D.h>
#include <Graphics/Shader2D.h>

class SimulationScene : public SceneBase {
private:
    NewtLoader m_Loader;

    std::shared_ptr<RoadNetwork> m_RoadNetwork;
    std::shared_ptr<Camera2D> m_Camera;
    std::shared_ptr<Shader2D> m_Shader;
    
public:
    SimulationScene();
    virtual void InitializeScene() override;
    virtual void HandleKeyPressed(int key) override;
    virtual void Render() override;
};