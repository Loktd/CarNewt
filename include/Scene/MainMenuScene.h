#pragma once

#include <Scene/SceneBase.h>

class MainMenuScene : public SceneBase
{
private:
public:
    MainMenuScene();
    virtual void HandleKeyPressed(int key) override;
};