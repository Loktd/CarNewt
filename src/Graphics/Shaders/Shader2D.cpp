#include <Graphics/Shaders/Shader2D.h>

static const char* g_VertexShaderSource = R"(
    #version 330
    precision highp float;

    uniform mat4 u_MVP;
    uniform int u_VertexIsTextured;
    uniform int u_VertexIsMultiColor;
    uniform vec4 u_OneColor;

    layout(location = 0) in vec2 modelCoordinates;
    layout(location = 1) in vec2 textureCoordinates;
    layout(location = 2) in vec4 vertexColor;

    out vec2 tCoordinates;
    out vec4 vColor;

    void main(){
        gl_Position = u_MVP * vec4(modelCoordinates.x, modelCoordinates.y, 0, 1);
        tCoordinates = u_VertexIsTextured > 0 ? textureCoordinates : vec2(0,0);
        vColor = u_VertexIsMultiColor > 0 ? vertexColor : u_OneColor;
    }
)";
static const char* g_FragmentShaderSource = R"(
    #version 330
    precision highp float;

    uniform int u_FragmentIsTextured;

    in vec2 tCoordinates;
    in vec4 vColor;

    out vec4 FragmentColor;

    void main(){
        FragmentColor = u_FragmentIsTextured > 0 ? vec4(1,1,1,1) : vColor;
    }
)";
static const char* g_FragmentColorName = "FragmentColor";

Shader2D::Shader2D() : ShaderProgram(g_VertexShaderSource, g_FragmentShaderSource, g_FragmentColorName) {}

void Shader2D::SetMVP(const glm::mat4& MVP)
{
    SetUniform(MVP, "u_MVP");
}

void Shader2D::SetFlags(bool isTextured, bool isMultiColor)
{
    int textured = isTextured ? 1 : 0;
    int multiColor = isMultiColor ? 1 : 0;
    SetUniform(textured, "u_FragmentIsTextured");
    // SetUniform(textured, "u_VertexIsTextured");
    SetUniform(multiColor, "u_VertexIsMultiColor");
}

void Shader2D::SetUniformColor(const glm::vec4& color)
{
    SetUniform(color, "u_OneColor");
}
