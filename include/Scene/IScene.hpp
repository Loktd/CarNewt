#pragma once

class IScene
{
public:
    virtual void HandleKeyPressed(int key) = 0;
    virtual void HandleKeyReleased(int key) = 0;
    virtual void HandleMousePressed(int button, int pX, int pY) = 0;
    virtual void HandleMouseReleased(int button, int pX, int pY) = 0;
    virtual void HandleMouseMotion(int pX, int pY) = 0;
    virtual void HandleTimeElapsed(double start, double end) = 0;

    virtual void Render() = 0;
};