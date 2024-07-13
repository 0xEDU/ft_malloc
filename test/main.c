#include "ft_malloc.h"
#include <assert.h>
#include <stddef.h>

int main() {
  // Tiny allocation
  void *tiny_ptr = malloc(42);
  assert(tiny_ptr == NULL);
  
  // Small allocation
  void *small_ptr = malloc(16442);
  assert(small_ptr == NULL);
  return 0;
}
