#include "ft_malloc.h"

long get_page_size() {
    return sysconf(_SC_PAGESIZE);
}
