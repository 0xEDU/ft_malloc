#include "ft_malloc.h"
#include <stdio.h>

void *malloc(size_t size) {
    (void) size;
    long page_size = sysconf(_SC_PAGESIZE);
    int fd = -1;
    if ((fd = open("/dev/zero", O_RDWR, 0) == -1)) {
        return NULL;
    }
    void *ptr = mmap(0, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        printf("Map failed");
        return NULL;
    }
    printf("%p\n", ptr);
	return NULL;
}
