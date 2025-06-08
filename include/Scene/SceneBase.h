#pragma once

#include <Engine/WindowingEngine.h>
#include <Scene/IScene.hpp>

class SceneBase : public IScene
{
private:
    glm::vec4 m_Color;
public:
    SceneBase(const glm::vec4& color);

    virtual void HandleKeyPressed(int key) override;
    virtual void HandleKeyReleased(int key) override;
    virtual void HandleMousePressed(int button, int pX, int pY) override;
    virtual void HandleMouseReleased(int button, int pX, int pY) override;
    virtual void HandleMouseMotion(int pX, int pY) override;
    virtual void HandleTimeElapsed(double start, double end) override;
    virtual void Render() override;
};
