#include "ft_malloc.h"
#include <assert.h>
#include <stddef.h>

int main() {
  void *ptr = malloc(42);
  assert(ptr == NULL);
  return 0;
}
