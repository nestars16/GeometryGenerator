#version 330 core

uniform float time;
uniform vec2 resolution;
uniform float redIntensity;
uniform float blueIntensity;
uniform float greenIntensity;
out vec4 fragColor;

void main()
{
    vec2 fragUv = gl_FragCoord.xy / resolution;

    float red   = 0.5 + 0.4 * sin(time  + fragUv.x * redIntensity);
    float blue  = 0.5 + 0.3 * cos(time  + fragUv.y * blueIntensity);
    float green = 0.5 + 0.2 * sin(time  + fragUv.x * greenIntensity+ fragUv.y * greenIntensity);  

    fragColor = vec4(red,blue,green,1.0);
}