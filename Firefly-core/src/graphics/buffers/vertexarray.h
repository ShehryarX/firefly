#pragma once

#include <vector>
#include <GL/glew.h>

#include "buffer.h"

namespace firefly {
	namespace graphics {

		class VertexArray {
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;
		public:
			VertexArray();
			virtual ~VertexArray();

			void addBuffer(Buffer *buffer, GLuint index);
			void bind() const;
			void unbind() const;
		};
	}
}