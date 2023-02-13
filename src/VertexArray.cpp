#ifndef __EMSCRIPTEN__
    #include "VertexArray.h"
#else
    #include "..\include\VertexArray.h"
#endif

glfwUtils::VertexArray::VertexArray(int n)
{
    glGenVertexArrays(n,&m_VOA);
    glBindVertexArray(m_VOA);
}

void glfwUtils::VertexArray::bind() const
{
    glBindVertexArray(m_VOA);
}

glfwUtils::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1,&m_VOA);
}

void glfwUtils::VertexArray::unbind() const
{
    glBindVertexArray(0);
}
