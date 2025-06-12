#pragma once

#include <string>

#include <Graphics/ShaderProgram.h>

class Shader2D : public ShaderProgram
{
private:
public:
    Shader2D();
    void SetMVP(const glm::mat4& MVP);
    void SetFlags(bool isTextured, bool isMultiColor);
    void SetUniformColor(const glm::vec4& color);
};