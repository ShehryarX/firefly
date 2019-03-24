#pragma once

#include "../renderer2d.h"
#include "../renderable2d.h"

namespace firefly {
	namespace graphics {
		class Layer {
		protected:
			Renderer2D *m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
			math::mat4 m_ProjectionMatrix;
		
		public:
			virtual ~Layer();
			virtual void add(Renderable2D *renderable);
			virtual void render();	

		protected:
			Layer(Renderer2D *renderer, Shader *shader, math::mat4 projectionMatrix);
		};

	}
}