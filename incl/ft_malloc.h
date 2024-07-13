#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#define MMAP(size) mmap(NULL, 1 * get_page_size(), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, 0, 0)

#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

// Malloc lib
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

// Internals
long get_page_size();

#endif // !FT_MALLOC_H
