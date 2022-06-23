#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);  // Function to read text from the shader text files

class Shader {
public:
	GLuint ID;  // Reference ID of the shader
	Shader(const char* vertexFile, const char* fragmentFile);  // Builds the shader program from 2 different shader text files

	void Activate();
	void Delete();

private:
	void compileErrors(unsigned int shader, const char* type);
};

#endif