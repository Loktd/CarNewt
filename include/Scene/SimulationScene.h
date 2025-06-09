#pragma once

#include <iostream>
#include <filesystem>

#include <Scene/SceneBase.h>
#include <Loader/NewtLoader.h>
#include <Engine/WindowingEngine.h>

class SimulationScene : public SceneBase {
private:
    NewtLoader m_Loader;
    std::shared_ptr<RoadNetwork> m_RoadNetwork;
public:
    SimulationScene();
    virtual void InitializeScene() override;
    virtual void HandleKeyPressed(int key) override;
};