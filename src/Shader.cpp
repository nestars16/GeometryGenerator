#include "Shader.h"

glfwUtils::Shader::Shader(const char* p_shaderSource, GLenum shaderType, const GLint* length): m_id{glCreateShader(shaderType)}
{
   
    glShaderSource(m_id,1,&p_shaderSource, length);
    glCompileShader(m_id);
}

glfwUtils::Shader::Shader(std::string filePath, GLenum shaderType) : m_id{glCreateShader(shaderType)} ,m_name{filePath}
{
    std::ifstream shaderSourceFile{filePath};
    std::string shaderCode{};

    
    if(!shaderSourceFile)
        throw std::runtime_error{"Failed to open shader file\n"};

    std::stringstream shaderSourceCode{};
    shaderSourceCode << shaderSourceFile.rdbuf();
    shaderSourceFile.close();

    shaderCode = shaderSourceCode.str();

    const char* sourceCodeCString{shaderCode.c_str()};
    
    glShaderSource(m_id,1,&sourceCodeCString, nullptr);
    glCompileShader(m_id);

}
