#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include "VBO.h"

class VAO {
public:
	GLuint ID;  // ID reference for the vertex array object
	VAO();  // Generate a vertex buffer object ID

	void LinkVBO(VBO VBO, GLuint layout);  // Links a vertex buffer object to the vertex array object using a certain layout
	void Bind();
	void UnBind();
	void Delete();
};

#endif