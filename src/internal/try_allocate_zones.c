#include "ft_malloc.h"
#include <sys/mman.h>

void try_allocate_zones(enum e_zone zone) {
  switch (zone) {
  case TINY:
    if (global_pointer_pool.tiny_zone_start == NULL) {
      global_pointer_pool.tiny_zone_start = MMAP(TINY_HEAP_ALLOCATION_SIZE);
      global_pointer_pool.tiny_zone_end =
          global_pointer_pool.tiny_zone_start + (TINY_HEAP_ALLOCATION_SIZE);
    }
    break;
  case SMALL:
    if (global_pointer_pool.small_zone_start == NULL) {
      global_pointer_pool.small_zone_start = MMAP(SMALL_HEAP_ALLOCATION_SIZE);
      global_pointer_pool.small_zone_end =
          global_pointer_pool.small_zone_start +
          (SMALL_HEAP_ALLOCATION_SIZE);
    }
    break;
  default:
    break;
  }
  return;
}
