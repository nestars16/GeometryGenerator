#version 330 core
uniform vec3 newColor;
out vec4 fragColor;
void main()
{
    fragColor = vec4(newColor,1.0);
}