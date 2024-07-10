#include "ft_malloc.h"
#include <unistd.h>

void *malloc(size_t size) {
	(void)size;
	write(1, "malloc\n", 7);
	return NULL;
}
