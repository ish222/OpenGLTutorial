#include "ShaderClass.h"

std::string get_file_contents(const char* filename) {
	std::ifstream in(filename, std::ios::binary);
	if (in) {
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
	throw errno;
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	std::string vertexCode = get_file_contents(vertexFile);  // Read shader text files
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();  // Convert std string to c strings (character arrays)
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);  // Creates a vertex shader object and assigns its reference value to this variable
	glShaderSource(vertexShader, 1, &vertexSource, NULL);  // Feeds the source code for the shader from the string above
	glCompileShader(vertexShader);  // Compiles the shader to machine code so that the GPU can use it

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	ID = glCreateProgram();  // In order to use the shaders, they need to be wrapped into a shader program
	glAttachShader(ID, vertexShader);  // Attaches the shader to the shader program
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);  // Wraps up the shader program

	glDeleteShader(vertexShader);  // Deletes the shaders as they are already in the program
	glDeleteShader(fragmentShader);
}

void Shader::Activate() {
	glUseProgram(ID);
}

void Shader::Delete() {
	glDeleteProgram(ID);
}
