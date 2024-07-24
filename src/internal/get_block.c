#include "ft_malloc.h"

void *get_block(t_zone_pointer_pool *pointer_pool, enum e_zone zone, int block_number) {
	switch (zone) {
	case TINY: {
		return pointer_pool->tiny_zone_start + (block_number * TINY_BLOCK_SIZE);
	}
	case SMALL: {
		return pointer_pool->small_zone_start + (block_number * SMALL_BLOCK_SIZE);
	}
	default:
		return NULL;
	}
}