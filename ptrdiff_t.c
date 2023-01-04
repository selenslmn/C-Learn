/* In C, two addresses can be subtracted from each other, provided they are of the same type. 
However, it cannot be added. In this case, the numeric components of the address are subtracted from each other.
The resulting value is divided by the length of the type of the address. 
In other words, as a result of the operation, the number of elements in between is obtained. */

#include <stdio.h>
	#include <stddef.h>

	int main(void)
	{
		int a[10];
		ptrdiff_t diff;

		diff = &a[5] - &a[0];

		printf("%td\n", diff);

		return 0;
	}
