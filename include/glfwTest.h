#ifndef GLFWTEST_H
#define GLFWTEST_H

#include <array>
#include "Shader.h"
#include "ShaderProgram.h"
#include <functional>
#include "geometryGeneratorConstants.h"

                //glGetProgramiv(0,0,0);
                //glGetShaderiv(shader,GL_COMPILE_STATUS,&success);


namespace glfwUtils
{
    template<typename... ObjectsToTest>
    void isBuildSucessful(
        std::function<void(GLuint,GLsizei,GLsizei*,GLchar*)> infoLogFunc,
    std::function<void(GLuint,GLenum,GLint*)> checkingFunction,
    GLenum checkFlag,
      const ObjectsToTest&... objects)
    {
        int successFlag{};
        char infoLog[GeometryGeneratorConstants::maxLogBuffer];

        for(const auto& object : {objects...})
        {
            checkingFunction(object,checkFlag,&successFlag);

            if(!successFlag)
            {
                infoLogFunc(object,GeometryGeneratorConstants::maxLogBuffer,nullptr,infoLog);
                std::cerr << "Object build failed: " << infoLog << '\n';
            }
            else
            {
                std::cout << "Object built Successfully\n";
            }

            
        }
    }

    
} // namespace glfwUtils



#endif