#include "ft_malloc.h"

void *malloc(size_t size) {
    (void) size;
    char *ptr = MMAP(1 * get_page_size());
    if (ptr == MAP_FAILED) {
        write(1, "mmap failed\n", 13);
        return NULL;
    }
    ptr[0] = 'a';
    write(1, ptr, 1);
	return NULL;
}
