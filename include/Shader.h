#ifndef SHADER_H
#define  SHADER_H


#ifndef __EMSCRIPTEN__
    #include <GLAD/glad.h>
#else
    #include <emscripten/emscripten.h>
    #define GLFW_INCLUDE_ES3
#endif
#include <GLFW/glfw3.h>

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string_view>

namespace glfwUtils
{
    class Shader
    {
        private:
        unsigned int m_id{};
        std::string_view m_name{};

        public:
            Shader(const char* shaderSource, unsigned int shaderType, const int* length);

            Shader(std::string filePath, unsigned int shaderType);

            operator unsigned int() const noexcept{return m_id;}

            std::string_view getName() const noexcept{return m_name;};
    };
}

#endif