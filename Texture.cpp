#include "Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
	type = texType;
	int widthImg, heightImg, numColCh;
	stbi_set_flip_vertically_on_load(true);  // Tells stb to read the image from the bottom left to top right to agree with OpenGL
	unsigned char* bytes = stbi_load("pingu.png", &widthImg, &heightImg, &numColCh, 0);  // Importing texture data as a char array

	glGenTextures(1, &ID);  // Generating the texture object
	glActiveTexture(slot);  // Insert the texture into the texture unit 0
	glBindTexture(texType, ID);  // Binding the texture 

	// Interpolation type for the texture, in this case GL_NEAREST interpolation is used when the image is scaled where the pixels are kept as they are
	// GL_LINEAR would instead create new pixels using local pixel data which may result in a blurrier image
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);  // This function is used to modify the texture settings
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Second setting is how the image is repeated, here GL_REPEAT simply repeats the texture along each specified axis (S and T)
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// If GL_CLAMP_TO_BORDER repeat pattern is used, the following code is needed
	// float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

	glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);  // Generate the texture
	glGenerateMipmap(texType);  // Generates the mipmap for the texture, which are smaller resolution versions of the texture for use when a smaller version is needed e.g far away

	stbi_image_free(bytes);  // Deletes the image data
	glBindTexture(texType, 0);  // Unbinds the texture
}

void Texture::texUint(Shader shader, const char* uniform, GLuint unit) {
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);  // Creates a unform containing the index of the slot for the tex0 variable
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind() {
	glBindTexture(type, ID);
}

void Texture::UnBind() {
	glBindTexture(type, 0);
}

void Texture::Delete() {
	glDeleteTextures(1, &ID);
}