#include <stdio.h>

#include "darray2.h"

int main()
{
	int* array_int = array(int);

	for (int i = 0; i < 100000; ++i)
	{
		array_append(array_int, i);
	}
	/*array_append(array_int, 5);
	array_append(array_int, 15);
	//my_array[1] = 3;
	int x = 2;
	array_append(array_int, x);
	array_insert(array_int, 1, 100);
	array_insert(array_int, 0, 150);*/

	printf("Length: %zd\n", array_length(array_int));
	for (int i = 0; i < array_length(array_int); ++i)
	{
		printf("Array[%d] = %d\n", i, array_int[i]);
	}

	/*float* array_float = array(float);
	array_append(array_float, 5.0f);
	array_append(array_float, 15.0f);
	//my_array[1] = 3;
	
	float y = 2.0f;
	array_append(array_float, y);

	printf("Length: %zd\n", array_length(array_float));
	for (int i = 0; i < array_length(array_float); ++i)
	{
		printf("Array[%d] = %f\n", i, array_float[i]);
	}*/

	return 0;
}