#pragma once

#include <glm/glm.hpp>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <Scene/IScene.hpp>

class SceneBase : public IScene
{
protected:
    glm::vec4 m_Color;
public:
    SceneBase(const glm::vec4& color);

    virtual void InitializeScene() override;
    virtual void HandleKeyPressed(int key) override;
    virtual void HandleKeyReleased(int key) override;
    virtual void HandleMousePressed(int button, int pX, int pY) override;
    virtual void HandleMouseReleased(int button, int pX, int pY) override;
    virtual void HandleMouseMotion(int pX, int pY) override;
    virtual void HandleTimeElapsed(double start, double end) override;
    virtual void Render() override;
};
