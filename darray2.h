#ifndef DARRAY_H
#define DARRAY_H

#include <stddef.h>
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
	(array) = enlarge_array_if_required(array, 1, sizeof(value)), \
	(array)[array_header(array)->length] = (value), \
	&(array)[array_header(array)->length++])

/*#define array_insert(array, pos, value) ( \
	(array) = enlarge_array_if_required(array, 1, sizeof(value)), \
	(array)[pos] = (value), \
	&(array)[pos])*/

void* array_init(size_t element_size, size_t initial_capacity);
void *enlarge_array_if_required(void *array, size_t item_count, size_t item_size);

#endif