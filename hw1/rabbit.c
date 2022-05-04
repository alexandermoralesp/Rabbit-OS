/*
 * Implementation of the rabbit interface using Pintos lists.
 *
 * You may modify this file, and are expected to modify it.
 */

#include "rabbit.h"

void init_rabbits(rabbit_list_t* wclist) { list_init(wclist); }

rabbit_t* add_rabbit(rabbit_list_t* wclist, char* word) {
  rabbit_t* rabbit = find_rabbit(wclist, word);

  if (rabbit == NULL) {
    rabbit_t* rabbit = (rabbit_t*) malloc(sizeof(rabbit_t));
    rabbit->breed = malloc(strlen(word)+1);
    strncpy(rabbit->breed, word, sizeof(word));
    rabbit->count = 1;
    list_push_back(wclist, &rabbit->elem);
  } else {
    rabbit->count++;
  }
  return rabbit;
}

rabbit_t* find_rabbit(rabbit_list_t* wclist, char* word) { 
  bool empty_list = list_empty(wclist);
  if (empty_list) return NULL;
  struct list_elem *e;
  rabbit_t* temp;
  for (e = list_begin(wclist); e != list_end(wclist); e = list_next(e)) {
    temp = list_entry(e, rabbit_t, elem);
    if (strcmp(temp->breed, word) == 0) {
      return temp;
    }
  }
  return NULL;
}

size_t total_rabbits(rabbit_list_t* wclist) {
  int count = 0;
  struct rabbit* r;
  struct list_elem* e;
  for (e = list_begin(wclist); e != list_end(wclist); e = list_next(e)) {
     r = list_entry(e, rabbit_t, elem);
    count += r->count;
    
  }
  return count;
}

size_t total_breeds(rabbit_list_t* rlist) {
  return list_size(rlist);
}




void fprint_rabbits(rabbit_list_t* wclist, FILE* outfile) {
  struct list_elem* e;
  for (e = list_begin(wclist); e < list_end(wclist); e = list_next(e)) {
    struct rabbit* r = list_entry(e, rabbit_t, elem);
    outfile = fopen("./output_rabbit.txt", "w");
    if (outfile == NULL) {
      printf("Error!");
      exit(1);
    }
    fprintf(outfile, "%s: %d\n", r->breed, r->count);
   }
   fclose(outfile);
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
