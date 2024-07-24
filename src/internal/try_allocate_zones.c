#include "ft_malloc.h"

void try_allocate_zones() {
  if (global_pointer_pool.small_zone_start == NULL) {
    global_pointer_pool.small_zone_start = MMAP(SMALL_HEAP_ALLOCATION_SIZE);
    global_pointer_pool.small_zone_end =
        global_pointer_pool.small_zone_start +
        (SMALL_HEAP_ALLOCATION_SIZE);
  }
  if (global_pointer_pool.tiny_zone_start == NULL) {
    global_pointer_pool.tiny_zone_start = MMAP(TINY_HEAP_ALLOCATION_SIZE);
    global_pointer_pool.tiny_zone_end =
        global_pointer_pool.tiny_zone_start + (TINY_HEAP_ALLOCATION_SIZE);
  }
  return;
}
