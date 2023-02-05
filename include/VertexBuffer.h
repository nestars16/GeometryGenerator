#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glfwUtils
{
        class VertexBuffer
        {
            private:
                unsigned int m_VBO;
                GLenum m_bufferType;

            public:
                VertexBuffer(int n, GLenum bufferType);
                
                void addData(GLsizeiptr size, const void * data, GLenum usage);

                ~VertexBuffer();

                void bind() const;
                void unbind() const;
        };
}

#endif