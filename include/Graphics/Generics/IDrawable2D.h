#pragma once

#include <memory>

#include <Graphics/Shaders/Shader2D.h>
#include <Graphics/Camera/Camera2D.h>

class IDrawable2D
{
private:
public:
    virtual void Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) = 0;
};
