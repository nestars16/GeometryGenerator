#ifndef GEOMETRYGENERATORCONSTANTS_H
#define GEOMETRYGENERATORCONSTANTS_H


namespace GeometryGeneratorConstants
{
    constexpr inline int windowWidth{800};
    constexpr inline int windowHeight{600};
    constexpr inline int maxLogBuffer{521};
   

    constexpr inline float triangleVertices[] = { 
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f};

     constexpr inline float colorfulTriangleVertices[] =
     {
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
     };

    constexpr inline float smallTriangles[] = { -0.75f, -0.5f,  0.0f,
                                            -0.25f,  -0.5f,  0.0f,
                                            -0.5f, 0.5f,  0.0f,
                                            };

    constexpr inline float smallTriangleRight[] = {0.75f, -0.5f,  0.0f,
                                            0.25f,  -0.5f,  0.0f,
                                            0.5f, 0.5f,  0.0f};
  

    constexpr inline float rectangleVertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

     constexpr inline unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };


    constexpr inline float pyramidVertices[] = 
    {
        -0.5f,0.0f,0.0f, //0
        0.5f,0.0f,0.0f, //1
        0.5f,0.0f,1.0f, //2
        -0.5f,0.0f,1.0f, //3
        0.0f,0.5f,0.5f //4

    };

    constexpr inline float pyramidComposition[] = 
    {
        -0.5f,0.0f,0.0f, 
        0.5f,0.0f,0.0f,
        0.5f,0.0f,1.0f,

         0.5f,0.0f,1.0f,
        -0.5f,0.0f,1.0f,
        -0.5f,0.0f,0.0f,

        0.5f,0.0f,1.0f,
        -0.5f,0.0f,1.0f,
        0.0f,0.75f,0.5f,

        0.5f,0.0f,0.0f,
        -0.5f,0.0f,0.0f,
        0.0f,0.75f,0.5f,

        -0.5f,0.0f,0.0f,
        -0.5f,0.0f,1.0f,
        0.0f,0.75f,0.5f,

        0.5f,0.0f,0.0f,
        0.5f,0.0f,1.0f,
        0.0f,0.75f,0.5f

    };



    constexpr inline unsigned int pyramidIndices[] = { 0,1,2,//base
                                                2,3,0,//base
                                                2,3,4,//
                                                3,0,4,
                                                0,1,4,
                                                1,3,4
                                                };

   constexpr inline float cubeVertices[] =
   {
    
    -0.5f,-0.5f,-0.5f, // triangle 1 : begin
    -0.5f,-0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f, // triangle 1 : end
    0.5f, 0.5f,-0.5f, // triangle 2 : begin
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f,-0.5f, // triangle 2 : end
    0.5f,-0.5f, 0.5f,
    -0.5f,-0.5f,-0.5f,
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f,-0.5f,
    0.5f,-0.5f,-0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f,-0.5f,
    0.5f,-0.5f, 0.5f,
    -0.5f,-0.5f, 0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f,-0.5f, 0.5f,
    0.5f,-0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f,-0.5f,
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f,-0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f, 0.5f,-0.5f,
    -0.5f, 0.5f,-0.5f,
    0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f,-0.5f, 0.5f

};


} // namespace TestingConstants


#endif