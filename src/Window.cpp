#include "Window.h"

glfwUtils::Window::Window(GLFWwindow* resource, GLFWframebuffersizefun callback):
m_windowResource{resource},m_resizeCallback{callback}
{
    if(!resource)
    {
        glfwTerminate();
        throw std::runtime_error{"Failed to create window\n"};
    }

    glfwMakeContextCurrent(m_windowResource);
    glfwSetFramebufferSizeCallback(m_windowResource,m_resizeCallback);
}

void glfwUtils::Window::setResizeCallback(GLFWframebuffersizefun newCallback)
{
    m_resizeCallback = newCallback;
    glfwSetFramebufferSizeCallback(m_windowResource,m_resizeCallback);
}

void glfwUtils::DefaultframeBufferCallback([[maybe_unused]]GLFWwindow* window,int width, int height)
{
    glViewport(0,0,width,height);
}