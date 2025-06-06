#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

void glfw_error_callback(int error, const char* description)
{
    std::cout << "[GLFW Error " << error << "]: " << description << "\n";
}

int main() {
    // Setting up error callback for glfw
    glfwSetErrorCallback(glfw_error_callback);

    // Initialize glfw and exit if there was failure
    int successful = glfwInit();
    if (successful == GLFW_FALSE) {
        exit(EXIT_FAILURE);
    }

    // OpenGL version 3.3 required
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Creating window
    GLFWwindow* window = glfwCreateWindow(800, 600, "CarNewt", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /*
        TODO: Set callbacks here
    */

    // Make the window the current context
    glfwMakeContextCurrent(window);

    // Load OpenGL functions
    gladLoadGL(glfwGetProcAddress);

    // Setting up swap interval
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, 800, 600);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}