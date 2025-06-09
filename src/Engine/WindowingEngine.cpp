#include <Engine/WindowingEngine.h>

WindowingEngine WindowingEngine::s_EngineInstance = WindowingEngine("CarNewt", 800, 600, 3, 3);

void WindowingEngine::error_callback(int error, const char* description)
{
    std::cerr << "[GLFW Error " << error << "]: " << description << "\n";
}

void WindowingEngine::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || GLFW_REPEAT) {
        s_EngineInstance.KeyPressed(key);
    }
    else if (action == GLFW_RELEASE) {
        s_EngineInstance.KeyReleased(key);
    }
}

void WindowingEngine::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (action == GLFW_PRESS) {
        s_EngineInstance.MousePressed(button, (int)xpos, (int)ypos);
    }
    else if (action == GLFW_RELEASE) {
        s_EngineInstance.MouseReleased(button, (int)xpos, (int)ypos);
    }
}

void WindowingEngine::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    s_EngineInstance.MouseMotion((int)xpos, (int)ypos);
}

void WindowingEngine::window_refresh_callback(GLFWwindow* window)
{
    s_EngineInstance.m_RefreshNeeded = true;
}

WindowingEngine::WindowingEngine(const char* title, int width, int height, int major, int minor) {
    m_Width = width;
    m_Height = height;

    // Setting up error callback for glfw
    glfwSetErrorCallback(WindowingEngine::error_callback);

    // Initialize glfw and exit if there was failure
    int successful = glfwInit();
    if (successful == GLFW_FALSE) {
        exit(EXIT_FAILURE);
    }

    // OpenGL version 3.3 required
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating window
    m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (m_Window == nullptr) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwSetWindowUserPointer(m_Window, this);

    // Setting up callbacks
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
    glfwSetCursorPosCallback(m_Window, cursor_position_callback);
    glfwSetKeyCallback(m_Window, key_callback);
    glfwSetWindowRefreshCallback(m_Window, window_refresh_callback);

    // Make the window the current context
    glfwMakeContextCurrent(m_Window);

    // Load OpenGL functions
    gladLoadGL(glfwGetProcAddress);

    // Setting up swap interval
    glfwSwapInterval(1);

    m_StartTime = 0;
    // Any initialization can run here
    Initialize();
}

WindowingEngine::~WindowingEngine()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}


WindowingEngine& WindowingEngine::GetInstance()
{
    return s_EngineInstance;
}

void WindowingEngine::Run()
{
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();

        double endTime = glfwGetTime();
        TimeElapsed(m_StartTime, endTime);
        m_StartTime = endTime;

        if (m_RefreshNeeded) {
            Render();
            glfwSwapBuffers(m_Window);
            m_RefreshNeeded = false;
        }
    }
}

void WindowingEngine::SwitchToScene(SceneName name)
{
    if (m_SceneMap.count(name) == 0) {
        throw UnknownSceneName("Scene name is not registered, cannot switch to non-existent scene.");
    }

    m_ActiveScene = m_SceneMap.at(name);
    m_ActiveScene->InitializeScene();
    Refresh();
}


void WindowingEngine::Exit()
{
    exit(EXIT_SUCCESS);
}

// Engine setup ends here, application specific stuff begins here

void WindowingEngine::Initialize()
{
    m_SceneMap[SceneName::MAIN_MENU] = std::make_shared<MainMenuScene>();
    m_SceneMap[SceneName::SIMULATION] = std::make_shared<SimulationScene>();

    SwitchToScene(SceneName::MAIN_MENU);
}

void WindowingEngine::Refresh()
{
    m_RefreshNeeded = true;
}

void WindowingEngine::Render()
{
    glViewport(0, 0, m_Width, m_Height);

    m_ActiveScene->Render();
}

void WindowingEngine::KeyPressed(int key)
{
    m_ActiveScene->HandleKeyPressed(key);
}

void WindowingEngine::KeyReleased(int key)
{
    m_ActiveScene->HandleKeyReleased(key);
}

void WindowingEngine::MousePressed(int button, int xpos, int ypos)
{
    m_ActiveScene->HandleMousePressed(button, xpos, ypos);
}

void WindowingEngine::MouseReleased(int button, int xpos, int ypos)
{
    m_ActiveScene->HandleMouseReleased(button, xpos, ypos);
}

void WindowingEngine::MouseMotion(int xpos, int ypos)
{
    m_ActiveScene->HandleMouseMotion(xpos, ypos);
}

void WindowingEngine::TimeElapsed(double start, double end)
{
    m_ActiveScene->HandleTimeElapsed(start, end);
}
