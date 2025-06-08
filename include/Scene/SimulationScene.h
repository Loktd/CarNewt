#pragma once

#include <Scene/SceneBase.h>

class SimulationScene : public SceneBase
{
private:
public:
    SimulationScene();
    virtual void HandleKeyPressed(int key) override;
};