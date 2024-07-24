#include "ft_malloc.h"
#include <assert.h>
#include <stddef.h>

int main() {
  // Tiny allocation
  void *tiny_ptr = malloc(42);
  assert(tiny_ptr != NULL);
  char *str = ft_strdup("ababa\n");
  write(1, str, 6);
  str = ft_strdup("cdcdc\n");
  write(1, str, 6);
  
  // Small allocation
  // void *small_ptr = malloc(16442);
  // assert(small_ptr == NULL);
  return 0;
}
