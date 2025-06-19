#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glad/gl.h>
#include <iostream>

class ShaderProgram
{
private:
    GLuint m_ProgramID;
    bool m_Usable;

    void SetUniform(int location, const int& value);
    void SetUniform(int location, const float& value);
    void SetUniform(int location, const glm::vec2& value);
    void SetUniform(int location, const glm::vec3& value);
    void SetUniform(int location, const glm::vec4& value);
    void SetUniform(int location, const glm::mat4& value);
public:
    ShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, const std::string& fragmentColorName = "FragmentColor");

    void Use();

    template<typename T>
    void SetUniform(const T& value, const std::string& uniformName);

    virtual ~ShaderProgram();
};

template<typename T>
inline void ShaderProgram::SetUniform(const T& value, const std::string& uniformName)
{
    int location = glGetUniformLocation(m_ProgramID, uniformName.c_str());
    if (location >= 0) {
        SetUniform(location, value);
    }
    else {
        std::cout << "No uniform with name \"" << uniformName << "\" can be found.";
    }
}
