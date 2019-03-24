#include "tilelayer.h"

namespace firefly {
	namespace graphics {
		// check far, near values
		TileLayer::TileLayer(Shader *shader) : Layer(new BatchRenderer2D(), shader, math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, 1.0f, 1.0f)) {

		}

		TileLayer::~TileLayer() {
		}
	}
}