#pragma once

#include "vec3.h"
#include "math_func.h"

namespace firefly {
	namespace math {
		float toRadians(float degrees);

		struct mat4 {
			float elements[4 * 4];

			mat4();
			mat4(float diagonal);

			static mat4 identity();
			mat4& multiply(const mat4 &other);

			friend mat4 operator*(mat4 left, const mat4 &right);
			mat4& operator*=(const mat4 &other);

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 projection(float fov, float aspectRatio, float near, float far);

			static mat4 translation(const vec3 &translation);
			static mat4 rotation(float angle, const vec3 &axis);
			static mat4 scale(const vec3 &scale);

		};
	}
}