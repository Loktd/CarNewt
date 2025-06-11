#include <Graphics/ShaderProgram.h>

void ShaderProgram::SetUniform(int location, const int& value)
{
    glUniform1i(location, value);
}

void ShaderProgram::SetUniform(int location, const float& value)
{
    glUniform1fv(location, 1, std::addressof(value));
}

void ShaderProgram::SetUniform(int location, const glm::vec2& value)
{
    glUniform2fv(location, 1, std::addressof(value.x));
}

void ShaderProgram::SetUniform(int location, const glm::vec3& value)
{
    glUniform3fv(location, 1, std::addressof(value.x));
}

void ShaderProgram::SetUniform(int location, const glm::vec4& value)
{
    glUniform4fv(location, 1, std::addressof(value.x));
}

void ShaderProgram::SetUniform(int location, const glm::mat4& value)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, (float*)(std::addressof(value)));
}

ShaderProgram::ShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, const std::string& fragmentColorName)
{
    m_Usable = false;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    if (vertexShader == 0) {
        std::cerr << "SHADER CREATION ERROR: Cannot create vertex shader.\n";
        return;
    }
    glShaderSource(vertexShader, 1, (const GLchar**)std::addressof(vertexShaderSource), nullptr);
    glCompileShader(vertexShader);

    GLint status = 0, length = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
    if (status == 0) {
        std::string message(length, '\0');
        glGetShaderInfoLog(vertexShader, length, nullptr, (GLchar*)message.data());
        std::cerr << "VERTEX SHADER COMPILATION ERROR: " << message << "\n";
        return;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    if (fragmentShader == 0) {
        std::cerr << "SHADER CREATION ERROR: Cannot create fragment shader.\n";
        return;
    }
    glShaderSource(fragmentShader, 1, (const GLchar**)std::addressof(fragmentShaderSource), nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
    if (status == 0) {
        std::string message(length, '\0');
        glGetShaderInfoLog(fragmentShader, length, nullptr, (GLchar*)message.data());
        std::cerr << "FRAGMENT SHADER COMPILATION ERROR: " << message << "\n";
        return;
    }

    m_ProgramID = glCreateProgram();
    if (m_ProgramID == 0) {
        std::cerr << "SHADER PROGRAM CREATION ERROR: Cannot create shader program.\n";
        return;
    }
    glAttachShader(m_ProgramID, vertexShader);
    glAttachShader(m_ProgramID, fragmentShader);

    glBindFragDataLocation(m_ProgramID, 0, fragmentColorName.c_str());

    glLinkProgram(m_ProgramID);

    glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &status);
    glGetProgramiv(m_ProgramID, GL_INFO_LOG_LENGTH, &length);
    if (status == 0) {
        std::string message(length, '\0');
        glGetProgramInfoLog(m_ProgramID, length, nullptr, (GLchar*)message.data());
        std::cerr << "SHADER LINKING ERROR: " << message << "\n";
        return;
    }

    m_Usable = true;
}

void ShaderProgram::Use()
{
    if (!m_Usable) {
        std::cerr << "SHADER PROGRAM USE ERROR: Cannot use shader program that is unusable.";
        return;
    }

    glUseProgram(m_ProgramID);
}

ShaderProgram::~ShaderProgram()
{
    if (m_ProgramID > 0) {
        glDeleteProgram(m_ProgramID);
    }
}
