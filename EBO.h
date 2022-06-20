#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>

class EBO {
public:
	GLuint ID;  // ID reference for the element array objeect
	EBO(GLuint* indices, GLsizeiptr size);  // Generate an element buffer object and link it to the indices

	void Bind();
	void UnBind();
	void Delete();
};

#endif
