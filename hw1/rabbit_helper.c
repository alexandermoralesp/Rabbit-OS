/*
 * Implementation of the rabbit comparator functions.
 *
 * You may modify this file, and are expected to modify it.
 */

#include "rabbit_helper.h"

bool less_count(const rabbit_t* r1, const rabbit_t* r2) {
  if (r1->count == r2->count) {
    return (r1->breed[0] < r2->breed[0]);
  }
  return (r1->count < r2->count);
};

bool less_word(const rabbit_t* r1, const rabbit_t* r2) {
  if (r1->breed[0] < r2->breed[0]) return true;
  return false;
};