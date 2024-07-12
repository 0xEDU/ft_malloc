#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

#endif // !FT_MALLOC_H
