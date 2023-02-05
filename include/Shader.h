#ifndef SHADER_H
#define  SHADER_H

#include <glad/glad.h>
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
            Shader(const char* shaderSource, GLenum shaderType, const GLint* length);

            Shader(std::string filePath, GLenum shaderType);

            operator GLuint() const noexcept{return m_id;}

            std::string_view getName() const noexcept{return m_name;};
    };
}

#endif