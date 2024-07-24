#include "ft_malloc.h"

void *malloc(size_t size) {
  try_allocate_zones();
  if (size <= (size_t)TINY_HEAP_ALLOCATION_SIZE) {
  } else if (size > (size_t)TINY_HEAP_ALLOCATION_SIZE &&
             size <= (size_t)SMALL_HEAP_ALLOCATION_SIZE) {
  } else if (size > (size_t)SMALL_HEAP_ALLOCATION_SIZE) {
    write(1, "not implemented", 15);
  }
  return NULL;
}
