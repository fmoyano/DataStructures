#include "darray.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Darray
{
	int capacity;
	int last_pos;
	int* elements;
} Darray;


//TODO: Using asserts
Darray* Darray_create(int initial_capacity)
{
	Darray* my_darray = malloc(sizeof(Darray));
	my_darray -> capacity = initial_capacity;
	my_darray -> last_pos = 0;
	my_darray -> elements = malloc(sizeof(int) * initial_capacity);
	return my_darray;
}

void Darray_add(Darray* array, int elem)
{
	//TODO: Handle enlarging the array
	array->elements[array->last_pos++] = elem;
}

int Darray_get(Darray* array, int pos)
{
	return array->elements[pos];
}

void Darray_remove(Darray* array, int pos)
{
	for (int i = pos;
		i < array -> last_pos;
		++i)
	{
		array->elements[i] = array->elements[i+1];
	}

	--array->last_pos;
}

int Darray_size(Darray* array)
{
	return array->last_pos;
}

void Darray_debug(Darray *array)
{
	int size = Darray_size(array);
	printf("Size: %d\n", size);
	for (int i = 0; i < size; ++i)
	{
		printf("Pos[%d] = %d\n", i, Darray_get(array, i));
	}
}

Darray Darray_new()
{
	Darray darray;
	return darray;
}
