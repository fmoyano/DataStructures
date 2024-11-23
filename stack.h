#ifndef STACK_H
#define STACK_H

#include "array.h"

#define stack(T) array(T)
#define stack_push(stack, value) array_append(stack, value)
#define stack_pop(stack) (--array_header(stack)->length, &stack[array_header(stack)->length]) 
#define stack_peek(stack) &stack[array_header(stack)->length - 1]
#define stack_length(stack) array_length(stack)
#define stack_empty(stack) array_length(stack) == 0
#define stack_clear(stack) array_clear(stack);

#endif