#version 330 core
out vec4 FragColor;

in vec4 textureColor;

void main()
{
    FragColor = textureColor;
}