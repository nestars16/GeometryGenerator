#ifndef WINDOW_H
#define WINDOW_H

#include <stdexcept>
#include <iostream>
#include <functional>

#ifndef __EMSCRIPTEN__
    #include <GLAD/glad.h>
#else
    #include <emscripten/emscripten.h>
    #define GLFW_INCLUDE_ES3
#endif
#include <GLFW/glfw3.h>

namespace glfwUtils
{
    class Window
    {
        private:
            GLFWwindow* m_windowResource{nullptr};
            GLFWframebuffersizefun m_resizeCallback{nullptr};

        public:

            Window(GLFWwindow* resource, GLFWframebuffersizefun);

            void setResizeCallback(GLFWframebuffersizefun newCallback);

            operator GLFWwindow*() const {return m_windowResource;}

           

    };


} // namespace glfwUtils


#endif