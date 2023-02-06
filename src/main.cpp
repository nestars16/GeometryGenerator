//cmake -S ..\..\ -B . -G "MinGW Makefiles" 

#include "..\dependencies\imgui-master\imgui.h"
#include "..\dependencies\imgui-master\imgui_impl_glfw.h"
#include "..\dependencies\imgui-master\imgui_impl_opengl3.h"
#include "..\dependencies\glm\glm\glm.hpp"
#include "..\dependencies\glm\glm\gtc\matrix_transform.hpp"
#include "..\dependencies\glm\glm\gtc\type_ptr.hpp"

//TODO

//animated backgrounds

//FUTURE
//Visualizer


#include <filesystem>
#include "Window.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "geometryGeneratorConstants.h"
#include "glfwTest.h"
#include "ShaderProgram.h"
#include "VertexArray.h"
#include "random.h"
#include "utils.h"

int main()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwUtils::Window mainWindow{glfwCreateWindow(GeometryGeneratorConstants::windowWidth,GeometryGeneratorConstants::windowHeight,"GeometryGenerator",nullptr,nullptr),glfwUtils::DefaultframeBufferCallback};

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }
    glfwSetCursorPosCallback(mainWindow,glfwUtils::mousePositionCallback);
    glEnable(GL_DEPTH_TEST);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    glfwUtils::StateInfo mouseInfo{};
    glfwSetWindowUserPointer(mainWindow,&mouseInfo);

    //shaders
   
    glfwUtils::Shader defaultVertex{ "../../shaders/rotational.vert",GL_VERTEX_SHADER};
    glfwUtils::Shader colorSliderShader{   "../../shaders/colorPicker.frag",GL_FRAGMENT_SHADER};
    glfwUtils::Shader changingColorShader{"../../shaders/rainbow.frag",GL_FRAGMENT_SHADER};
    glfwUtils::Shader lavaLampShader{"../../shaders/lavaLamp.frag",GL_FRAGMENT_SHADER};
    glfwUtils::Shader swirlShader{"../../shaders/blackAndWhite.frag",GL_FRAGMENT_SHADER};

    glfwUtils::isBuildSucessful(
        static_cast<std::function<void(GLuint,GLsizei,GLsizei*,GLchar*)>>(glGetShaderInfoLog),
        static_cast<std::function<void(GLuint,GLenum,GLint*)>>(glGetShaderiv),
        GL_COMPILE_STATUS,
        defaultVertex,colorSliderShader,changingColorShader,lavaLampShader,swirlShader
        );

    glfwUtils::ShaderProgram colorPickerProgram{defaultVertex,colorSliderShader};
    glfwUtils::ShaderProgram rainbowProgram{defaultVertex,changingColorShader};
    glfwUtils::ShaderProgram lavaLampProgram{defaultVertex,lavaLampShader};
    glfwUtils::ShaderProgram swirlProgram{defaultVertex,swirlShader};

    glfwUtils::isBuildSucessful(
        static_cast<std::function<void(GLuint,GLsizei,GLsizei*,GLchar*)>>(glGetProgramInfoLog),
        static_cast<std::function<void(GLuint,GLenum,GLint*)>>(glGetProgramiv),
        GL_LINK_STATUS,
        colorPickerProgram,rainbowProgram,lavaLampProgram,swirlProgram
        );

    std::array<std::reference_wrapper<glfwUtils::ShaderProgram>,static_cast<size_t>(glfwUtils::Shaders::maxShaders)> shaderArray{colorPickerProgram,rainbowProgram,lavaLampProgram,swirlProgram};

    glfwUtils::VertexArray pyramidVAO{1};
    glfwUtils::VertexBuffer pyramidVBO{1,GL_ARRAY_BUFFER};
    pyramidVBO.addData(sizeof(GeometryGeneratorConstants::pyramidComposition),GeometryGeneratorConstants::pyramidComposition,GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glfwUtils::VertexArray cubeVAO{1};
    glfwUtils::VertexBuffer cubeVBO{1,GL_ARRAY_BUFFER};
    cubeVBO.addData(sizeof(GeometryGeneratorConstants::cubeVertices),GeometryGeneratorConstants::cubeVertices,GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    cubeVAO.unbind();

    int shapeState{0};
    int currentShader{0};

    float colors[] = { Random::NCDrand(Random::randomizer),Random::NCDrand(Random::randomizer),Random::NCDrand(Random::randomizer)};
    float backgroundColors[] = {0.2f, 0.3f, 0.3f};
    float lavaLampIntensity[] = {0.2f, 0.1f, 0.9f};
    bool freeFloat{false};
    
    

    while(!glfwWindowShouldClose(mainWindow))
    {

        glfwPollEvents();

        mouseInfo.processUserInput(mainWindow);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        //rendering 
        if(mouseInfo.drawGUI)
        {
            ImGui::Begin("Color Options");
        
            if(currentShader == static_cast<int>(glfwUtils::Shaders::colorPicker))
                ImGui::SliderFloat3("Shape Colors", colors, 0.0f,1.0f);

            if(currentShader == static_cast<int>(glfwUtils::Shaders::lavaLamp))
                ImGui::SliderFloat3("Color Intensity",lavaLampIntensity,0.0f,50.0f);

            ImGui::SliderFloat3("Background Color",backgroundColors,0.0f,1.0f);
            ImGui::End();
            
        
            ImGui::Begin("Shape");
            ImGui::RadioButton("Pyramid",&shapeState,static_cast<int>(glfwUtils::Shapes::TRIANGLE));
            ImGui::RadioButton("Cube",&shapeState,static_cast<int>(glfwUtils::Shapes::CUBE));
            ImGui::End();
        
            ImGui::Begin("Shaders");
            ImGui::RadioButton("Color Picker",&currentShader,static_cast<int>(glfwUtils::Shaders::colorPicker));
            ImGui::RadioButton("Rainbow",&currentShader,static_cast<int>(glfwUtils::Shaders::rainbow));
            ImGui::RadioButton("Lava Lamp",&currentShader,static_cast<int>(glfwUtils::Shaders::lavaLamp));
            ImGui::RadioButton("Swirl",&currentShader,static_cast<int>(glfwUtils::Shaders::swirl));

            ImGui::End();
        
        
            ImGui::Begin("Options");
            ImGui::Checkbox("Free float",&freeFloat);
            ImGui::End();
        }        
        
        glClearColor(backgroundColors[0], backgroundColors[1], backgroundColors[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //shader program
        
        shaderArray[static_cast<std::size_t>(currentShader)].get().use();

        if(currentShader == static_cast<int>(glfwUtils::Shaders::colorPicker))
        {
    
            auto colorPickerColor{glGetUniformLocation(colorPickerProgram,"newColor")};
            glUniform3f(colorPickerColor,colors[0],colors[1],colors[2]);
        }

        if(currentShader == static_cast<int>(glfwUtils::Shaders::rainbow) ||
         currentShader == static_cast<int>(glfwUtils::Shaders::lavaLamp) ||
         currentShader == static_cast<int>(glfwUtils::Shaders::swirl) 
         )
        {
            
            auto uniformTimeLocation{glGetUniformLocation(shaderArray[static_cast<std::size_t>(currentShader)].get(),"time")};
            glUniform1f(uniformTimeLocation,static_cast<float>(glfwGetTime()));

            auto resolutionUniformLocation{glGetUniformLocation(shaderArray[static_cast<std::size_t>(currentShader)].get(),"resolution")};
            glUniform2f(resolutionUniformLocation,
            static_cast<float>(mouseInfo.windowSize.first),
            static_cast<float>(mouseInfo.windowSize.second));
            
        }

        if(currentShader == static_cast<int>(glfwUtils::Shaders::lavaLamp))
        {

            auto redUniformLocation{glGetUniformLocation(lavaLampProgram,"redIntensity")};            
            auto blueUniformLocation{glGetUniformLocation(lavaLampProgram,"blueIntensity")};
            auto greenUniformLocation{glGetUniformLocation(lavaLampProgram,"greenIntensity")};

            glUniform1f(redUniformLocation,lavaLampIntensity[0]);
            glUniform1f(blueUniformLocation,lavaLampIntensity[1]);
            glUniform1f(greenUniformLocation,lavaLampIntensity[2]);

        }

        glm::mat4 model{1.0f};
        model = glm::rotate(model, freeFloat? static_cast<float>(glfwGetTime()): glm::radians(mouseInfo.mouseRotationInfo.first),mouseInfo.mouseRotationInfo.second);
        glm::mat4 view{1.0f};
        view = glm::translate(view,glm::vec3(0.0f,sin(glfwGetTime())/6,-3.0f));
        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        auto modelMatrixPosition{glGetUniformLocation(shaderArray[static_cast<std::size_t>(currentShader)].get(),"model")};
        glUniformMatrix4fv(modelMatrixPosition,1,GL_FALSE,glm::value_ptr(model));
        auto viewMatrixPosition{glGetUniformLocation(shaderArray[static_cast<std::size_t>(currentShader)].get(),"view")};
        glUniformMatrix4fv(viewMatrixPosition,1,GL_FALSE,glm::value_ptr(view));
        auto projectionMatrixPosition{glGetUniformLocation(shaderArray[static_cast<std::size_t>(currentShader)].get(),"projection")};
        glUniformMatrix4fv(projectionMatrixPosition,1,GL_FALSE,glm::value_ptr(projection));

        if(shapeState == static_cast<int>(glfwUtils::Shapes::TRIANGLE))
        {
            pyramidVAO.bind();
            glDrawArrays(GL_TRIANGLES,0,sizeof(GeometryGeneratorConstants::pyramidComposition)/sizeof(GeometryGeneratorConstants::pyramidComposition[0]));
        }
        
        if(shapeState == static_cast<int>(glfwUtils::Shapes::CUBE))
        {
            cubeVAO.bind();
            glDrawArrays(GL_TRIANGLES,0,sizeof(GeometryGeneratorConstants::cubeVertices)/sizeof(GeometryGeneratorConstants::cubeVertices[0]));
        }

        

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(mainWindow);
        
    }

    
    glfwTerminate();
    return 0;
}

