// Many programming languages have functions that give random real numbers between 0 and 1 in their standard library.
// However, there is no such function in C. The best way to achieve this in C is as follows:
// result = (double)rand() / RAND_MAX;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	double result;

	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		result = (double)rand() / RAND_MAX;
		printf("%f\n", result);
	}

	return 0;
}

----------------------------------------------------------------------------------------------------------------------------
  
