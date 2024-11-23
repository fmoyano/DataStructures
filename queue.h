#ifndef QUEUE_H
#define QUEUE_H

#include "array.h"

#define queue(T) array(T)
#define queue_push(queue, value) array_insert(queue, 0, value)
#define queue_pop(queue) (--array_header(queue)->length, &queue[array_header(queue)->length]) 
#define queue_peek(queue) &queue[array_header(queue)->length - 1]
#define queue_length(queue) array_length(queue)
#define queue_empty(queue) array_length(queue) == 0
#define queue_clear(queue) array_clear(queue)

#endif