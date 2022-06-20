#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO {
public:
	GLuint ID;  // ID reference for the vertex buffer object
	VBO(GLfloat* vertices, GLsizeiptr size);  // Generate Vertex Buffer object and link it to the vertices

	void Bind();
	void UnBind();
	void Delete();
};

#endif