#version 330 core

uniform float time;
//uniform vec3 uv;
uniform vec2 resolution;
out vec4 fragColor;


vec3 hsl2rgb(vec3 c)
{
    vec3 rgb = clamp(abs(mod(c.x * 6.0 + vec3(0.0,4.0,2.0),6.0)-3.0) -1.0,0.0,1.0);

    return c.z + c.y * (rgb-0.5) * (1.0 - abs(2.0 * c.z - 1.0));
}

void main()
{
    vec2 fragUv = gl_FragCoord.xy / resolution;

    vec4 rainbow = vec4(hsl2rgb(vec3(time + fragUv.x + fragUv.y,0.5,0.5)),1.0);
   
    fragColor = rainbow;
}