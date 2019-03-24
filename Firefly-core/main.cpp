#pragma comment(lib, "legacy_stdio_definitions.lib")

#include "src/graphics/window.h"
#include "src/math/math.h"
#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"
#include "src/graphics/renderable2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/sprite.h"
#include "src/graphics/batchrenderer2d.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/utils/timer.h"

#include <time.h>

#define BATCH_RENDERER 1

int main() {
	using namespace firefly;
	using namespace graphics;
	using namespace math;

	Window window("Firefly", 960, 540);
	
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader *s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader &shader = *s;
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	shader.enable();

	TileLayer layer(&shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1) {
		for (float x = -16.0f; x < 16.0f; x += 0.1) {
			layer.add(new Sprite(x, y, 0.09f, 0.09f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	layer.add(new Sprite(0, 0, 2, 2, math::vec4(0.8f, 0.2f, 0.8f, 1.0f)));
	
	Timer time;
	float timer = 0.0f;
	unsigned int frames = 0;

	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.enable();
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));

		layer.render();
		window.update();

		frames++;

		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}