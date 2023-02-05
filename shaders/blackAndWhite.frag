#version 330 core

uniform float time;
uniform vec2 resolution;
out vec4 fragColor;

void main()
{
    vec2 fragUv = (gl_FragCoord.xy / resolution);
    vec2 offset = vec2(0.5,0.25);

    float angle = atan(-fragUv.y + offset.y, fragUv.x - offset.x) * 0.1;
    float len = length(fragUv - offset);

    vec3 color = vec3(0.0) + sin(len * 50.0 + angle * 40.0 + time);

    fragColor = vec4(color,1.0);

}