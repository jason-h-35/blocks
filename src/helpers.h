#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_stdinc.h>

#define EPSILON SDL_FLT_EPSILON
#define PI SDL_PI_F

#define max(a, b) SDL_max(a, b)
#define min(a, b) SDL_min(a, b)
#define clamp(x, a, b) SDL_clamp(x, a, b)

#define deg(rad) ((rad) * 180.0 / PI)
#define rad(deg) ((deg) * PI / 180.0)
// #define abs(x) ((x) > 0 ? (x) : -(x)) already in stdlib

#define assert(e) SDL_assert(e)
#define static_assert(a, b) _Static_assert(a, b)

typedef enum {
	DIRECTION_N,
	DIRECTION_S,
	DIRECTION_E,
	DIRECTION_W,
	DIRECTION_U,
	DIRECTION_D,
	DIRECTION_2 = 4,
	DIRECTION_3 = 6,
} direction_t;

extern const int directions[][3];

void sort_2d(const int x, const int z, void* data, const int size);
