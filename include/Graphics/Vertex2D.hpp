#pragma once

#include <glm/glm.hpp>

struct Vertex2D
{
    glm::vec2 m_Position;
    glm::vec2 m_TextureCoordinates;
    glm::vec4 m_Color;

    Vertex2D(const glm::vec2& position) : m_Position(position), m_TextureCoordinates(0, 0), m_Color(0, 0, 0, 0) {}
    Vertex2D(const glm::vec2& position, const glm::vec2& texture) : m_Position(position), m_TextureCoordinates(texture), m_Color(0, 0, 0, 0) {}
    Vertex2D(const glm::vec2& position, const glm::vec4& color) : m_Position(position), m_TextureCoordinates(0, 0), m_Color(color) {}
};


struct TexturedVertex2D
{
    glm::vec2 m_Position;
    glm::vec2 m_TextureCoordinates;

    TexturedVertex2D(const glm::vec2& position, const glm::vec2& texture) : m_Position(position), m_TextureCoordinates(texture) {}
};

struct MultiColorVertex2D
{
    glm::vec2 m_Position;
    glm::vec4 m_Color;

    MultiColorVertex2D(const glm::vec2& position, const glm::vec4& color) : m_Position(position), m_Color(color) {}
};

struct SingleColorVertex2D
{
    glm::vec2 m_Position;

    SingleColorVertex2D(const glm::vec2& position) : m_Position(position) {}
};
