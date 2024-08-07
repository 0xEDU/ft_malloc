#ifndef FT_MALLOC_H
#define FT_MALLOC_H

// Macros
#define MMAP(size)                                                             \
  mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, 0, 0)
#define TINY_HEAP_ALLOCATION_SIZE (4 * get_page_size())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 100)
#define SMALL_HEAP_ALLOCATION_SIZE (100 * get_page_size())
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 100)

// System includes
#include <fcntl.h>
#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>

// Custom includes
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libput.h"
#include "enums/e_zone.h"
#include "types/t_zone_pointer_pool.h"

// Malloc lib
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

// Internals functions
long get_page_size();
void *get_block(t_zone_pointer_pool *pointer_pool, enum e_zone zone, int block_number);
void try_allocate_zones(t_zone_pointer_pool *pointer_pool);

#endif // !FT_MALLOC_H
