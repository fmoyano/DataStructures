#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main()
{
	int* stack_int = stack(int);
	stack_push(stack_int, 1);
	stack_push(stack_int, 2);
	stack_push(stack_int, 3);
	printf("Length of stack: %zd\n", stack_length(stack_int));
	printf("Stack empty: %d\n", stack_empty(stack_int));

	int* val = stack_pop(stack_int);
	printf("Value in stack: %d\n", *val);
	printf("Length of stack: %zd\n", stack_length(stack_int));
	printf("Stack empty: %d\n", stack_empty(stack_int));

	val = stack_pop(stack_int);
	printf("Value in stack: %d\n", *val);
	printf("Length of stack: %zd\n", stack_length(stack_int));
	printf("Stack empty: %d\n", stack_empty(stack_int));

	val = stack_pop(stack_int);
	printf("Value in stack: %d\n", *val);
	printf("Length of stack: %zd\n", stack_length(stack_int));
	printf("Stack empty: %d\n", stack_empty(stack_int));

	stack_clear(stack_int);
	printf("After stack clear: %zd\n", stack_length(stack_int));

	int* queue_int = queue(int);
	queue_push(queue_int, 1);

	for (int i = 0; i < queue_length(queue_int); ++i)
	{
		printf("Queue[%d] = %d\n", i, queue_int[i]);
	}

	queue_push(queue_int, 2);

	for (int i = 0; i < queue_length(queue_int); ++i)
	{
		printf("Queue[%d] = %d\n", i, queue_int[i]);
	}

	queue_push(queue_int, 3);

	for (int i = 0; i < queue_length(queue_int); ++i)
	{
		printf("Queue[%d] = %d\n", i, queue_int[i]);
	}

	printf("Length of queue: %zd\n", queue_length(queue_int));
	printf("Queue empty: %d\n", queue_empty(queue_int));

	int* val_queue = queue_pop(queue_int);
	printf("Value in queue: %d\n", *val);
	printf("Length of queue: %zd\n", queue_length(queue_int));
	printf("Queue empty: %d\n", queue_empty(queue_int));

	val = queue_pop(queue_int);
	printf("Value in queue: %d\n", *val);
	printf("Length of queue: %zd\n", queue_length(queue_int));
	printf("Queue empty: %d\n", queue_empty(queue_int));

	val = queue_pop(queue_int);
	printf("Value in queue: %d\n", *val);
	printf("Length of queue: %zd\n", queue_length(queue_int));
	printf("Queue empty: %d\n", queue_empty(queue_int));

	queue_clear(queue_int);
	printf("After queue clear; length: %zd\n", queue_length(queue_int));

	return 0;
}