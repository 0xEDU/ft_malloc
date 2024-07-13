#include "ft_malloc.h"

void *malloc(size_t size) {
  if (size >= 0 && size <= (size_t)TINY_HEAP_ALLOCATION_SIZE) {

  } else if (size > (size_t)TINY_HEAP_ALLOCATION_SIZE &&
             size <= (size_t)SMALL_HEAP_ALLOCATION_SIZE) {

  } else if (size > (size_t)SMALL_HEAP_ALLOCATION_SIZE) {
  }
  return NULL;
}
