#ifndef FT_MALLOC_H
#define FT_MALLOC_H

// Macros
#define MMAP(size)                                                             \
  mmap(NULL, 1 * get_page_size(), PROT_READ | PROT_WRITE,                      \
       MAP_PRIVATE | MAP_ANON, 0, 0)
#define TINY_HEAP_ALLOCATION_SIZE (4 * get_page_size())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
#define SMALL_HEAP_ALLOCATION_SIZE (16 * get_page_size())
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)

// System includes
#include <fcntl.h>
#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>

// Custom includes
#include "enums/e_zone.h"
#include "types/t_zone_pointer_pool.h"

// Malloc lib
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

// Internals functions
long get_page_size();
void try_allocate_zones(enum e_zone zone);

static t_zone_pointer_pool global_pointer_pool;

#endif // !FT_MALLOC_H
