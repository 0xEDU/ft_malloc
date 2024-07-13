#include "enums/e_zone.h"
#include "ft_malloc.h"

void try_allocate_zones(t_zone_enum zone) {
  static t_zone_pointer_pool pointer_pool;
  (void) pointer_pool;
  switch (zone) {
  case TINY:
    write(1, "tini", 4);
    break;
  case SMALL:
    write(1, "smol", 4);
    break;
  default:
    break;
  }
  return;
}
