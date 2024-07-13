#include "ft_malloc.h"

void *malloc(size_t size) {
  if (size <= (size_t)TINY_HEAP_ALLOCATION_SIZE) {
    try_allocate_zones(TINY);
  } else if (size > (size_t)TINY_HEAP_ALLOCATION_SIZE &&
             size <= (size_t)SMALL_HEAP_ALLOCATION_SIZE) {
    try_allocate_zones(SMALL);
  } else if (size > (size_t)SMALL_HEAP_ALLOCATION_SIZE) {
    write(1, "not implemented", 15);
  }
  return NULL;
}
