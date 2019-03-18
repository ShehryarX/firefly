#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace firefly { 
	namespace graphics {
		class Window {
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
		public:
			Window(const char *name, int width, int height);
			virtual ~Window();
			void clear() const;
			void update();
			bool closed() const;

			int getWidth() const;
			int getHeight() const;

		private:
			bool init();
		};
	} 
}