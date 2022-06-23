#version 330 core
// version of OpenGL and the profile used

// Outputs a vec4 of colours in the format RGBA
out vec4 FragColor;

// Inputs the 'variable' colour from the vertex shader
in vec3 color;

// Inputs texture coordinates from the vertex shader
in vec2 texCoord;

uniform sampler2D tex0;

void main()
{
	FragColor = texture(tex0, texCoord);
}