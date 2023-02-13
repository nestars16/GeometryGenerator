#ifndef  SHADERPROGRAM_H
#define SHADERPROGRAM_H

#ifndef __EMSCRIPTEN__
    #include "GLAD\glad.h"
#else
   // unsigned int glCreateProgram();
   // void glAttachShader(unsigned int program,unsigned int shader);
   // void glLinkProgram(unsigned int program);
   // void glUseProgram(unsigned int program);
   #include <emscripten/emscripten.h>
   #define GLFW_INCLUDE_ES3
#endif
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