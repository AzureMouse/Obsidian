#include "Renderer.h"
#include <GL/glew.h>
#include <iostream>
#include "VertexBuffer.h"

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char *function, const char *file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "OPENGL ERROR";
		return false;
	}

	return true;
}


void Renderer::draw(int value)
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);
	glUniform4f(value, 1.0f, 0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 0, 4);


}
