#include "enums/e_zone.h"
#include "ft_malloc.h"

void try_allocate_zones(t_zone_enum zone) {
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
