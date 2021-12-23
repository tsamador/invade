#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 textureColor;


uniform float xOffset = 0.0f;
uniform float yOffset = 0.0f;

void main()
{
    gl_Position = vec4(aPos.x + xOffset, aPos.y + yOffset, aPos.z, 1.0);
    textureColor = vec4(aColor, 1.0f);
}