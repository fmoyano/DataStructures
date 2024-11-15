#ifndef DARRAY_H
#define DARRAY_H

#include <stddef.h>

typedef struct Darray Darray;

Darray* Darray_create(int initial_capacity, size_t bytes_per_element);
void Darray_append(Darray* array, void* elem);
void Darray_add(Darray* array, int pos, void* elem);
void* Darray_get(Darray* array, int pos);
void Darray_remove(Darray* array, int pos);
size_t Darray_length(Darray* array);
void Darray_debug(Darray* array);

#endif