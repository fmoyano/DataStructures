#ifndef DARRAY_H
#define DARRAY_H

typedef struct Darray Darray;

Darray* Darray_create(int initial_capacity);
void Darray_add(Darray* array, int elem);
int Darray_get(Darray* array, int pos);
void Darray_remove(Darray* array, int pos);
int Darray_size(Darray* array);
void Darray_debug(Darray* array);

#endif