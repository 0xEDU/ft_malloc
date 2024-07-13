#include "ft_malloc.h"
#include <stdio.h>
#include <string.h>

void *malloc(size_t size) {
    (void) size;
    long page_size = sysconf(_SC_PAGESIZE);
    char *ptr = mmap(NULL, 1 * page_size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, 0, 0);
    if (ptr == MAP_FAILED) {
        write(1, "mmap failed\n", 13);
        return NULL;
    }
    ptr[0] = 'a';
	return NULL;
}
