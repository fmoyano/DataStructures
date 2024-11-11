#include <stdio.h>

#include "darray.h"

int main()
{
	Darray* array = Darray_create(10);

	Darray_debug(array);
	
	Darray_add(array, 1);
	Darray_add(array, 20);
	Darray_add(array, 35);

	Darray_debug(array);

	Darray_remove(array, 0);

	Darray_debug(array);

	Darray_remove(array, 1);

	Darray_debug(array);

	Darray_remove(array, 0);

	Darray_debug(array);

	Darray_add(array, 100);
	Darray_add(array, 2);
	Darray_add(array, 45);
	Darray_add(array, 28);
	Darray_add(array, 5);
	
	Darray_debug(array);

	return 0;
}