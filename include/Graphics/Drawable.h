#pragma once

#include <memory>

class ShaderProgram;

class Drawable
{
private:
public:
    virtual void Draw(std::shared_ptr<ShaderProgram> shader) = 0;
};
