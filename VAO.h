#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include "VBO.h"

class VAO {
public:
	GLuint ID;  // ID reference for the vertex array object
	VAO();  // Generate a vertex buffer object ID

	// This function tells OpenGL how to interpret the data sent to the shader, layout: 0 = coordinates/position, 1 = colour
	// numComponents = number of components per layout e.g. xyz coordinates = 3, RGB colours = 3
	// type = type of our components, in this example = GLfloat
	// stride = size of the bytes from the beginning of one vertex to the beginning of the next, in this example = 6*sizeof(GLfloat)
	// offset = the initial offset of a layout in bytes, for position offset = 0, for colours offset = 3*sizeof(GLfloat) since first 3 components are coordinates
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	
	void Bind();
	void UnBind();
	void Delete();
};

#endif