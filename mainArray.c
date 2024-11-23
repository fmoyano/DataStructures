#include <stdio.h>
#include "array.h"

int main()
{
	int* array_int = array(int);

	for (int i = 0; i < 30; ++i)
	{
		int* x = array_append(array_int, i);
		printf("Introducing %d in array\n", *x);
	}

	int* val1 = array_insert(array_int, 1, 500);
	int *val2 = array_insert(array_int, 2, 1000);
	int *val3 = array_insert(array_int, 3, 700);
	int *val4 = array_insert(array_int, 4, 850);

	printf("Length: %zd\n", array_length(array_int));
	for (int i = 0; i < array_length(array_int); ++i)
	{
		printf("Array[%d] = %d\n", i, array_int[i]);
	}

	array_clear(array_int);
	printf("After clear; length: %zd\n", array_length(array_int));
	for (int i = 0; i < array_length(array_int); ++i)
	{
		printf("Array[%d] = %d\n", i, array_int[i]);
	}

	/*printf("Val1 = %d\n", *val1);
	printf("Val2 = %d\n", *val2);
	printf("Val3 = %d\n", *val3);
	printf("Val4 = %d\n", *val4);

	int *val5 = array_insert(array_int, 20, 7);
	printf("Val5 = %d\n", *val5);

	printf("Length: %zd\n", array_length(array_int));
	for (int i = 0; i < array_length(array_int); ++i)
	{
		printf("Array[%d] = %d\n", i, array_int[i]);
	}

	array_removeAt(array_int, 21);
	
	printf("Length: %zd\n", array_length(array_int));
	for (int i = 0; i < array_length(array_int); ++i)
	{
		printf("Array[%d] = %d\n", i, array_int[i]);
	}

	array_removeAt(array_int, 0);

	printf("Length: %zd\n", array_length(array_int));
	for (int i = 0; i < array_length(array_int); ++i)
	{
		printf("Array[%d] = %d\n", i, array_int[i]);
	}

	array_removeAt(array_int, 6);

	printf("Length: %zd\n", array_length(array_int));
	for (int i = 0; i < array_length(array_int); ++i)
	{
		printf("Array[%d] = %d\n", i, array_int[i]);
	}*/

	return 0;
}