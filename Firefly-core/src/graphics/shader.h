#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../math/math.h"
#include "../utils/fileutils.h"

namespace firefly {
	namespace graphics {
		class Shader {
		private:
			GLuint m_ShaderID;
			const char *m_VertPath;
			const char *m_FragPath;
		
		public:
			Shader(const char *vertex, const char *fragPath);
			~Shader();

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, float value);
			void setUniform2f(const GLchar* name, const math::vec2 &vector);
			void setUniform3f(const GLchar* name, const math::vec3 &vector);
			void setUniform4f(const GLchar* name, const math::vec4 &vector);

			void setUniformMat4(const GLchar* name, const math::mat4 &matrix);
			 
			void enable() const;
			void disable() const;
		
		private:
			GLuint load();
			GLint getUniformLocation(const GLchar *name);
		};
	}
}