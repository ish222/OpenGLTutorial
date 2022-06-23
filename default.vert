#version 330 core

// Layout for position which is first
layout (location = 0) in vec3 aPos;

// Layout for colours
layout (location = 1) in vec3 aColor;

// Layout for texture coordinates
layout (location = 2) in vec2 aTex;

// Outputs a vec3 of colours for the fragment shader
out vec3 color;

// Outputs a vec2 of texture coordinates for the fragment shader
out vec2 texCoord;

// Variable to control the scale of the vertices
uniform float scale;

void main()
{
	gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
	color = aColor;
	texCoord = aTex;
}