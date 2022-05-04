/*
 * Implementation of the rabbit interface using Pintos lists.
 *
 * You may modify this file, and are expected to modify it.
 */

#include "rabbit.h"

void init_rabbits(rabbit_list_t* wclist) { list_init(&wclist); }

size_t total_rabbits(rabbit_list_t* wclist) {
  int count = 0;
  struct list_elem* e;
  for (e = list_begin(&wclist); e != list_end(&wclist); e = list_next(e)) {
    struct rabbit* r = list_entry(e, rabbit_t, elem);
    count += r->count;
  }
  return count;
}

size_t total_breeds(rabbit_list_t* rlist) {
  int count = 0;
  
  char *breeds = malloc(sizeof(char)*100);

  struct list_elem* e;
  for (e = list_begin(&rlist); e != list_end(&rlist); e = list_next(e)) {
    struct rabbit* r = list_entry(e, rabbit_t, elem);
    int index = (int) r->breed % 100;
    breeds[index] += 1;
  }

  for (int i = 0; i < 100; i++) {
    if (breeds[i] != 0) count++;
  }
  free(breeds);
  return count;
}

rabbit_t* find_rabbit(rabbit_list_t* wclist, char* word) { 
  struct list_elem* e;
  for (e = list_begin(&wclist); e < list_end(&wclist); e = list_next(e)) {
    struct rabbit* r = list_entry(e, rabbit_t, elem);
    if (r->breed == word) {
      return r;
    }
   }
  return NULL; 
}

rabbit_t* add_rabbit(rabbit_list_t* wclist, char* word) {
  struct list_elem* e;
  for (e = list_begin(&wclist); e < list_end(&wclist); e = list_next(e)) {
    struct rabbit* r = list_entry(e, rabbit_t, elem);
    if (r->breed == word) {
      r->count++;
      return r;
    }
   }
  return NULL;
}

void fprint_rabbits(rabbit_list_t* wclist, FILE* outfile) {
  
}

static bool less_list(const struct list_elem* ewc1,
                      const struct list_elem* ewc2, void* aux) {
  /* TODO */
  return false;
}

void rabbit_sort(rabbit_list_t* wclist,
                 bool less(const rabbit_t*, const rabbit_t*)) {
  list_sort(wclist, less_list, less);
}
