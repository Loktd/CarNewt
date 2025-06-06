#ifndef ENGINE_H_
#define ENGINE_H_

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

class WindowingEngine
{
private:
    static WindowingEngine s_EngineInstance;

    GLFWwindow* m_Window;
    int m_Width, m_Height;
    double m_StartTime;
    bool m_RefreshNeeded;

    void Initialize();
    void Refresh();
    void Render();
    void KeyPressed(int key);
    void KeyReleased(int key);
    void MousePressed(int button, int xpos, int ypos);
    void MouseReleased(int button, int xpos, int ypos);
    void MouseMotion(int xpos, int ypos);
    void TimeElapsed(double start, double end);

    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    static void window_refresh_callback(GLFWwindow* window);

    WindowingEngine(const char* title, int width, int height, int major, int minor);
    ~WindowingEngine();
public:
    WindowingEngine(const WindowingEngine& copied) = delete;

    static WindowingEngine& GetInstance();

    bool keepRunning();
    void run();
};


#endif // MAINWINDOW_H_