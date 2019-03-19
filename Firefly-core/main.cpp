#pragma comment(lib, "legacy_stdio_definitions.lib")

#include "src/graphics/window.h"

int main() {
	using namespace firefly;
	using namespace graphics;

	Window window("Firefly", 960, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// GLuint vao;
	// glGenVertexArrays(1, &vao);
	// glBindVertexArray(vao);

	while (!window.closed()) {
		// std::cout << window.getWidth() << "," << window.getHeight() << std::endl;
		window.clear();
		// if (window.isKeyPressed(GLFW_KEY_A)) {
		// 	std::cout << "Pressed key A" << std::endl;
		// }
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			std::cout << "Pressed Mouse Button" << std::endl;
			double x, y;
			window.getMousePosition(x, y);
			std::cout << "Mouse position " << x << ", " << y << std::endl;
		}
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		// glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}
	
	return 0;
}