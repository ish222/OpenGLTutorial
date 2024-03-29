#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size) {  // sizeiptr is the type used by OpenGL for sizes in bytes
	// Constructor generates a vertex buffer object and links it to the vertices
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::UnBind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
	glDeleteBuffers(1, &ID);
}