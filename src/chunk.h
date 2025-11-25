#pragma once

#include "block.h"
#include "config.h"
#include "helpers.h"
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
	CHUNK_TYPE_OPAQUE,
	CHUNK_TYPE_TRANSPARENT,
	CHUNK_TYPE_COUNT,
} chunk_type_t;

typedef struct {
	block_t blocks[CHUNK_X][CHUNK_Y][CHUNK_Z];
	SDL_GPUBuffer* vbos[CHUNK_TYPE_COUNT];
	uint32_t sizes[CHUNK_TYPE_COUNT];
	uint32_t capacities[CHUNK_TYPE_COUNT];
	bool load;
	bool mesh;
} chunk_t;

void chunk_wrap(int* x, int* y, int* z);
bool chunk_in(const int x, const int y, const int z);
void chunk_set_block(chunk_t* chunk, const int x, const int y, const int z, const block_t block);

typedef struct {
	chunk_t* chunks[WORLD_X][WORLD_Z];
	int x;
	int z;
} terrain_t;

void terrain_init(terrain_t* terrain);
void terrain_free(terrain_t* terrain);
chunk_t* terrain_get(const terrain_t* terrain, const int x, const int z);
bool terrain_in(const terrain_t* terrain, const int x, const int z);
bool terrain_border(const terrain_t* terrain, const int x, const int z);
void terrain_neighbors(terrain_t* terrain, const int x, const int z,
					   chunk_t* neighbors[DIRECTION_2]);
chunk_t* terrain_get2(const terrain_t* terrain, int x, int z);
bool terrain_in2(const terrain_t* terrain, int x, int z);
bool terrain_border2(const terrain_t* terrain, int x, int z);
void terrain_neighbors2(terrain_t* terrain, int x, int z, chunk_t* neighbors[DIRECTION_2]);
int* terrain_move(terrain_t* terrain, const int x, const int z, int* size);
