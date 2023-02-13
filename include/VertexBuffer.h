#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#ifndef __EMSCRIPTEN__
    #include <GLAD/glad.h>
#else
    #include <emscripten/emscripten.h>
    #define GLFW_INCLUDE_ES3

//void glGenBuffers
//void glBindBuffers
//void glDeleteBuffers
//void glBufferData


#endif

    #include <GLFW/glfw3.h>


namespace glfwUtils
{
        class VertexBuffer
        {
            private:
                unsigned int m_VBO;
                unsigned int m_bufferType;

            public:
                VertexBuffer(int n, unsigned int bufferType);
                
                void addData(ptrdiff_t size, const void * data, unsigned int usage);

                ~VertexBuffer();

                void bind() const;
                void unbind() const;
        };
}

#endif