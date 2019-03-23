#include "batchrenderer2d.h"

namespace firefly {
	namespace graphics {
		BatchRenderer2D::BatchRenderer2D() {
			init();
		}

		BatchRenderer2D::~BatchRenderer2D() {
			delete m_IBO;
			glDeleteBuffers(1, &m_VBO);
		}

		void BatchRenderer2D::init() {
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);

			glGenBuffers(1, &m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW);
			
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid *)0);
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid *)(3 * sizeof(GLfloat)));
			
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		
			GLushort indices[RENDERER_INDICES_SIZE];

			int offset = 0;

			for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6) {
				indices[i + 0] = offset + 0;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;

				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;

				offset += 4;
			}

			m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

			glBindVertexArray(0);
		}

		void BatchRenderer2D::begin() {
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}
		
		void BatchRenderer2D::submit(const Renderable2D *renderable) {
			const math::vec3 &position = renderable->getPosition();
			const math::vec2 &size= renderable->getSize();
			const math::vec4 &color= renderable->getColor();

			m_Buffer->vertex = position;
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = math::vec3(position.x, position.y + size.y, position.z);
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = math::vec3(position.x + size.x, position.y + size.y, position.z);
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = math::vec3(position.x + size.x, position.y, position.z);
			m_Buffer->color = color;
			m_Buffer++;
			
			m_IndexCount += 6;
		}

		void BatchRenderer2D::end() {
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void BatchRenderer2D::flush() {
			glBindVertexArray(m_VAO);
			m_IBO->bind();

			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, nullptr);

			m_IBO->unbind();
			glBindVertexArray(0);

			m_IndexCount = 0;
		}
	}
}