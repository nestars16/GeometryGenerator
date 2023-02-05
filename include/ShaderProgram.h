#ifndef  SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "GLAD\glad.h"
#include "GLFW\glfw3.h"
#include "Shader.h"

namespace glfwUtils
{

        class ShaderProgram
        {
        private: 
            unsigned int m_id{};

        public:
            template<typename... Shaders>
                ShaderProgram(Shaders&... shaders_p) : m_id{glCreateProgram()}
                {
                    for(const auto& shader : {shaders_p...})
                    {
                        glAttachShader(m_id, shader);
                    }

                    glLinkProgram(m_id);
                }

            

            operator GLuint() const {return m_id;}

            void use(){
                 
                glUseProgram(m_id);
                }

            ~ShaderProgram()
            {
                //glDeleteProgram(m_id);
            }

           
        };

}
#endif