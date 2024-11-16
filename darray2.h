#ifndef DARRAY_H
#define DARRAY_H

#include <stddef.h>
#include <string.h>

#define INITIAL_ARRAY_CAPACITY 16

//The example from Dylan Falconer used custom allocators that defaulted to std allocators
/*typedef struct {
    void *(*alloc)(size_t bytes, void *context);
    void *(*free)(size_t bytes, void *ptr, void *context);
    void *context;
} Allocator;*/

typedef struct {
    size_t length;
    size_t capacity;
    //size_t padding_or_something; // prefer 16-byte alignment
    //Allocator *a;
} Array_Header;

#define array_header(array) ((Array_Header *)(array) - 1)
#define array_length(array) (array_header(array)->length)
#define array_capacity(array) (array_header(array)->capacity)

#define array(T) array_init(sizeof(T), INITIAL_ARRAY_CAPACITY)

#define array_append(array, value) ( \
	(array) = enlarge_array_if_required(array, array_header(array)->length, sizeof(value)), \
	(array)[array_header(array)->length] = (value), \
	&(array)[array_header(array)->length++])

#define array_insert(array, pos, value) \
	((pos) == array_header(array)->length) ? \
		array_append(array, value) : \
	((array) = enlarge_array_if_required(array, pos, sizeof(value)), \
	(array)[(pos)] = (value), \
	&(array)[(pos)]); \

#define array_removeAt(array, pos) \
{ \
	Array_Header* header = array_header(array); \
	if ((pos) == header->length) \
	{ \
		--header->length; \
	} \
	else if (header->length > 1 && (pos) < header->length) \
	{ \
		void *ptr = &array[(pos)]; \
		void *last_element = &array[header->length-1]; \
		--header->length; \
		memcpy(ptr, last_element, sizeof(*array)); \
	} \
}

void* array_init(size_t element_size, size_t initial_capacity);
void *enlarge_array_if_required(void *array, size_t pos, size_t item_size);

#endif