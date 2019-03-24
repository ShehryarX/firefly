#pragma once

#include "layer.h"
#include "../batchrenderer2d.h"

namespace firefly {
	namespace graphics {
		class TileLayer : public Layer {
		public:
			TileLayer(Shader *shader);
			virtual ~TileLayer();
		};
	}
}