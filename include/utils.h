#ifndef UTILS_H
#define UTILS_H


#include "Window.h"
#include "..\dependencies\glm\glm\glm.hpp"
#include "geometryGeneratorConstants.h"
#include <cmath>


namespace glfwUtils
{
    enum class Shapes
    {
        TRIANGLE,
        CUBE
    };

    enum class Shaders
    {
        colorPicker,
        rainbow,
        lavaLamp,
        swirl,
        maxShaders,
    };

    enum class Quadrants
    {
        I,
        II,
        III,
        IV
    };

    struct MouseInfo
    {
        std::pair<double,double> firstPress{0.0,0.0}; 
        std::pair<double,double> continousPress{0.0,0.0};
        std::pair<float,glm::vec3> rotationInfo{0.1f,glm::vec3(0.1f,0.1f,0.1f)};
        bool active{false};
        std::pair<int,int> windowSize{};
        void processUserInput(const glfwUtils::Window& window);

    };

    void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    //void processMouseInput(const glfwUtils::Window& window,glfwUtils::MouseInfo& mouse);
    

    std::pair<float,glm::vec3> calculateRotation(const MouseInfo& mousePos);

    void DefaultframeBufferCallback([[maybe_unused]]GLFWwindow* window,int width, int height);
    
}


#endif