#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#ifndef __EMSCRIPTEN__
    #include "GLAD/glad.h"
#else
    #include <emscripten/emscripten.h>
    #define GLFW_INCLUDE_ES3
#endif

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