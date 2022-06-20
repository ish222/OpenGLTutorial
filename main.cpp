#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;

GLfloat vertices[] = {
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,  // Coordinates for the left, right and top corner for an equilateral triangle for a shader
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,

	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,  // Coordinates for the inner smaller upside down triangle, left then right then down
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
};

GLuint indices[] = {  // This is an index buffer to allow OpenGL to reuse a vertex and save memory
	0, 3, 5,  // Lower left small triangle
	3, 2, 4,  // Lower right small triangle
	5, 4, 1  // Upper small triangle
};

int main() {
	glfwInit();  // Initialise GLFW so its functions can be used

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // Tell GLFW the major version of OpenGL in use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // Core profile of OpenGL contains the modern functions

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test Program", NULL, NULL);

	if (window == NULL) {
		std::cout << "Error: Unable to create window." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);  // Initialises the created window onto the current context

	gladLoadGL();  // Loads the needed configurations for OpenGL

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	Shader shaderProgram("default.vert", "default.frag");  // Creates a shader object from the vertices and fragment shader text files

	VAO VAO1;  // Generate and bind vertex array object
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));  // Generate the vertex buffer object and the element buffer object and link them to the vertices and indices respectively
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);  // Link VBO to VAO
	VAO1.UnBind();  // Unbind all buffers to prevent accidentally modifying them
	VBO1.UnBind();
	EBO1.UnBind();

	while (!glfwWindowShouldClose(window)) {  // This condition only passes when the user closes the window or due to a function call
		glClearColor(0.917f, 0.062f, 0.062f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();  // Activates the shader program we created above
		VAO1.Bind();  // Binds the VAO of interest
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);  // Draws the triangle
		glfwSwapBuffers(window);

		glfwPollEvents();  // Tells GLFW to process poll events like window apprearance or resizing, etc...
	}

	// Cleanup code to delete buffer objects and shader program
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}