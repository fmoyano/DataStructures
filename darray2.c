#include "darray2.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void* array_init(size_t element_size, size_t initial_capacity)
{
	void* ptr = 0;

	size_t size = sizeof(Array_Header) + initial_capacity * element_size;
	Array_Header *header = malloc(size);

	if (header)
	{
		header->length = 0;
		header->capacity = initial_capacity;
		ptr = header + 1; //first address for storing array elements
	}

	return ptr;
}

void *enlarge_array_if_required(void *array, size_t pos, size_t item_size)
{
	Array_Header* header = array_header(array);

	//Make sure to return null pointer so that client code fails if it tries to insert beyond length
	if (pos > header->length) return 0;
	
	size_t desired_capacity =  pos == header->length ? header->length + 1 : header->length;

	if (header->capacity < desired_capacity)
	{
		size_t new_capacity = header->capacity * 2;
		while (new_capacity < desired_capacity)
		{
			new_capacity *= 2;
		}
		printf("New capacity: %zd\n", new_capacity);

		size_t new_size = sizeof(Array_Header) + new_capacity * item_size;
		Array_Header* new_header = realloc(header, new_size);

		if (new_header)
		{
			//We don't increment the length, since it's going to be incremented later in the Macro that called this
			new_header->capacity = new_capacity;
			printf("New header created: length %zd capacity %zd\n", new_header->length, new_header->capacity);
			header = new_header + 1;
		}
		else
		{
			header = 0;
		}
	}
	else
	{
		printf("No need to increase current capacity: length %zd capacity %zd\n", header->length, header->capacity);
		++header;
	}

	return header;
}