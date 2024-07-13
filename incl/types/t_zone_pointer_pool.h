#ifndef T_ZONE_POINTERS_H
#define T_ZONE_POINTERS_H

typedef struct s_zone_pointer_pool {
  void *tiny_zone_start;
  void *tiny_zone_end;
  void *small_zone_start;
  void *small_zone_end;
} t_zone_pointer_pool;

#endif // T_ZONE_POINTERS_H