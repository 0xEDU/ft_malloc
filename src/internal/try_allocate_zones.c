#include "ft_malloc.h"

void try_allocate_zones(t_zone_pointer_pool *pointer_pool) {
  if (pointer_pool->small_zone_start == NULL) {
    pointer_pool->small_zone_start = MMAP(SMALL_HEAP_ALLOCATION_SIZE);
    pointer_pool->small_zone_end =
        pointer_pool->small_zone_start +
        (SMALL_HEAP_ALLOCATION_SIZE);
  }
  if (pointer_pool->tiny_zone_start == NULL) {
    pointer_pool->tiny_zone_start = MMAP(TINY_HEAP_ALLOCATION_SIZE);
    pointer_pool->tiny_zone_end =
        pointer_pool->tiny_zone_start + (TINY_HEAP_ALLOCATION_SIZE);
  }
  return;
}
