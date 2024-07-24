#include "ft_malloc.h"

void *malloc(size_t size) {
  static int next_block[2] = {0, 0};
  static t_zone_pointer_pool pointer_pool;

  try_allocate_zones(&pointer_pool);
  if (size <= (size_t)TINY_HEAP_ALLOCATION_SIZE) {
    return get_block(&pointer_pool, TINY, next_block[TINY]++);
  } else if (size > (size_t)TINY_HEAP_ALLOCATION_SIZE &&
             size <= (size_t)SMALL_HEAP_ALLOCATION_SIZE) {
    return get_block(&pointer_pool, SMALL, next_block[SMALL]++);
  } else if (size > (size_t)SMALL_HEAP_ALLOCATION_SIZE) {
    write(1, "not implemented", 15);
  }
  return NULL;
}
