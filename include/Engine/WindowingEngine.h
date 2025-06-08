#pragma once

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

#include <Scene/IScene.hpp>
#include <Scene/SceneNames.hpp>

class WindowingEngine
{
private:
    static WindowingEngine s_EngineInstance;

    GLFWwindow* m_Window;
    int m_Width, m_Height;
    double m_StartTime;
    bool m_RefreshNeeded;
    std::unordered_map<SceneName, std::shared_ptr<IScene>> m_SceneMap;
    std::shared_ptr<IScene> m_ActiveScene;

    void Initialize();
    void Refresh();
    void Render();
    void KeyPressed(int key);
    void KeyReleased(int key);
    void MousePressed(int button, int pX, int pY);
    void MouseReleased(int button, int pX, int pY);
    void MouseMotion(int pX, int pY);
    void TimeElapsed(double start, double end);

    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double pX, double pY);
    static void window_refresh_callback(GLFWwindow* window);

    WindowingEngine(const char* title, int width, int height, int major, int minor);
    WindowingEngine(const WindowingEngine& copied) = delete;
    ~WindowingEngine();
public:
    static WindowingEngine& GetInstance();

    void Run();
    void SwitchToScene(SceneName name);
    void Exit();
};