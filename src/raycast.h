#pragma once

#include <stdbool.h>

bool raycast(float* x, float* y, float* z, const float dx, const float dy, const float dz,
			 const bool previous);
