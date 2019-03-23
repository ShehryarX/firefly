#pragma once

#include <GL/glew.h>
#include "buffers//buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"

#include "../math/math.h"
#include "shader.h"

namespace firefly {
	namespace graphics {

		struct VertexData {
			math::vec3 vertex;
			math::vec4 color;
		};

		class Renderable2D {
		protected:
			math::vec3 m_Position;
			math::vec2 m_Size;
			math::vec4 m_Color;



		public:
			Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color) : m_Position(position), m_Size(size), m_Color(color) { }

			virtual ~Renderable2D() { }

			inline const math::vec3 &getPosition() const { return m_Position; }
			inline const math::vec2 &getSize() const { return m_Size; }
			inline const math::vec4 &getColor() const { return m_Color; }
		};
	}
}