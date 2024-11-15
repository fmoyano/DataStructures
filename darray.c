#include "darray.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Darray
{
	int capacity;
	size_t length;
	size_t element_size;
	unsigned char* elements;
} Darray;

//TODO: Using asserts
Darray* Darray_create(int initial_capacity, size_t bytes_per_element)
{
	Darray* my_darray = malloc(sizeof(Darray));
	my_darray -> capacity = initial_capacity;
	my_darray -> length = 0;
	my_darray -> element_size = bytes_per_element;
	my_darray -> elements = malloc(initial_capacity * bytes_per_element);
	return my_darray;
}

void Darray_append(Darray* array, void* elem)
{
	//TODO: Handle enlarging the array
	memcpy(array->elements + array->length * array->element_size, elem, array->element_size);
	++array->length;
}

void Darray_add(Darray* array, int pos, void* elem)
{
	//TODO: Handle enlarging the array
	memcpy(array->elements + pos * array->element_size, elem, array->element_size);
	++array->length;
}


void* Darray_get(Darray* array, int pos)
{
	return array->elements + pos * array->element_size;
}

void Darray_remove(Darray* array, int pos)
{
	return;
	/*for (int i = pos;
		i < array -> last_pos;
		++i)
	{
		array->elements[i] = array->elements[i+1];
	}

	--array->last_pos;*/
}

size_t Darray_length(Darray* array)
{
	return array->length;
}

void Darray_debug(Darray *array)
{
	int length = Darray_length(array);
	printf("Size: %d\n", length);
	/*for (int i = 0; i < size; ++i)
	{
		printf("Pos[%d] = %d\n", i, Darray_get(array, i));
	}*/
}