/*
 * Implementation of the rabbit interface using Pintos lists.
 *
 * You may modify this file, and are expected to modify it.
 */


#include "rabbit.h"

void init_rabbits(rabbit_list_t* wclist) { /* TODO */
}

size_t total_rabbits(rabbit_list_t* wclist) {
  /* TODO */
  return 0;
}

size_t total_breeds(rabbit_list_t* rlist) {
    /* TODO */
  return 0;
}

rabbit_t* find_rabbit(rabbit_list_t* wclist, char* word) {
  /* TODO */
  return NULL;
}

rabbit_t* add_rabbit(rabbit_list_t* wclist, char* word) {
  /* TODO */
  return NULL;
}

void fprint_rabbits(rabbit_list_t* wclist, FILE* outfile) { /* TODO */
}

static bool less_list(const struct list_elem* ewc1, const struct list_elem* ewc2, void* aux) {
  /* TODO */
  return false;
}

void rabbit_sort(rabbit_list_t* wclist,
                    bool less(const rabbit_t*, const rabbit_t*)) {
  list_sort(wclist, less_list, less);
}
