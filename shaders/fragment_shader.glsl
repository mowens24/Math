#version 330 core
out vec4 FragColor;

uniform vec3 plotColor;

void main()
{
    FragColor = vec4(plotColor, 1.0);
}
