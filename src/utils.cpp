#include "utils.h"


void glfwUtils::mousePositionCallback([[maybe_unused]]GLFWwindow* window,[[maybe_unused]] double xpos,[[maybe_unused]] double ypos)
{
        glfwUtils::MouseInfo* mouseCoordsPointer{static_cast<glfwUtils::MouseInfo*>(glfwGetWindowUserPointer(window))};

        
        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && mouseCoordsPointer->active)
        {
                mouseCoordsPointer->continousPress.first = xpos; 
                mouseCoordsPointer->continousPress.second = ypos;
                return; 
        }

        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !mouseCoordsPointer->active)
        {
                mouseCoordsPointer->firstPress.first = xpos;
                mouseCoordsPointer->firstPress.second = ypos;
                return;
        }


        if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE && mouseCoordsPointer->active)
        {
               mouseCoordsPointer->active = false;
        }
        
}



void glfwUtils::MouseInfo::processUserInput(const glfwUtils::Window& window)
{
        
        if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
                rotationInfo.first = static_cast<float>(abs(continousPress.first + firstPress.second));
                //std::cout << "Angle intensity " << rotationInfo.first << '\n';

                rotationInfo.second = glm::vec3{
                static_cast<float>(std::atan(continousPress.second - firstPress.second)),
                static_cast<float>(glm::radians(continousPress.first - firstPress.first)/3.0f),
               
               0.0f
                        };

                
        }

        if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS)
        {
                rotationInfo.second.z += 0.5f;
        }

        if(glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS)
        {
                rotationInfo.second.z -= 0.5f;
                
        }

        

}



 
