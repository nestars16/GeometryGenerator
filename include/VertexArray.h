#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

namespace glfwUtils
{
    class VertexArray
    {
    private:    
        GLuint m_VOA;
    public:
        VertexArray(int n);

        void bind() const;
        void unbind() const;

        ~VertexArray();

    };
    
}


#endif