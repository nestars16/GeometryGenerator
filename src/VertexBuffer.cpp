#include "VertexBuffer.h"

glfwUtils::VertexBuffer::VertexBuffer(int n, GLenum bufferType): m_bufferType{bufferType}
{
    glGenBuffers(n,&m_VBO);
    glBindBuffer(bufferType,m_VBO);
}

void glfwUtils::VertexBuffer::addData(GLsizeiptr size, const void * data, GLenum usage)
{
    glBufferData(m_bufferType,size,data,usage);
}

glfwUtils::VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1,&m_VBO);
}

void glfwUtils::VertexBuffer::bind() const
{
    glBindBuffer(m_bufferType,m_VBO);
}

void glfwUtils::VertexBuffer::unbind() const
{
    glBindBuffer(m_bufferType,0);
}
