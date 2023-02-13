#ifndef __EMSCRIPTEN__
        #include "utils.h"
#else
        #include "..\include\utils.h"
#endif

void glfwUtils::mousePositionCallback([[maybe_unused]]GLFWwindow* window,[[maybe_unused]] double xpos,[[maybe_unused]] double ypos)
{
        glfwUtils::StateInfo* mouseCoordsPointer{static_cast<glfwUtils::StateInfo*>(glfwGetWindowUserPointer(window))};

        
        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && mouseCoordsPointer->mouseActive)
        {
                mouseCoordsPointer->mouseContinousPress.first = xpos; 
                mouseCoordsPointer->mouseContinousPress.second = ypos;
                return; 
        }

        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !mouseCoordsPointer->mouseActive)
        {
                mouseCoordsPointer->mouseFirstPress.first = xpos;
                mouseCoordsPointer->mouseFirstPress.second = ypos;
                return;
        }


        if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE && mouseCoordsPointer->mouseActive)
        {
               mouseCoordsPointer->mouseActive = false;
        }
        
}



void glfwUtils::StateInfo::processUserInput(const glfwUtils::Window& window)
{
        
        if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
                mouseRotationInfo.first = static_cast<float>(abs(mouseContinousPress.first + mouseFirstPress.second));
                //std::cout << "Angle intensity " << rotationInfo.first << '\n';

                mouseRotationInfo.second = glm::vec3{
                static_cast<float>(std::atan(mouseContinousPress.second - mouseFirstPress.second)),
                static_cast<float>(glm::radians(mouseContinousPress.first - mouseFirstPress.first)/3.0f),
               
               0.0f
                        };

                
        }

        if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS)
        {
                mouseRotationInfo.second.z += 0.5f;
        }

        if(glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS)
        {
                mouseRotationInfo.second.z -= 0.5f;
                
        }

        if(glfwGetKey(window,GLFW_KEY_F1) == GLFW_PRESS)
        {
                drawGUI = !drawGUI;
        }

}


void glfwUtils::DefaultframeBufferCallback([[maybe_unused]]GLFWwindow* window,int width, int height)
{
    glfwUtils::StateInfo* mouseCoordsPointer{static_cast<glfwUtils::StateInfo*>(glfwGetWindowUserPointer(window))};
    
    mouseCoordsPointer->windowSize.first = width;
    mouseCoordsPointer->windowSize.second = height;

    glViewport(0,0,width,height);
}
 
