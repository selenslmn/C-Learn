// find pi by generating random numbers.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N		10000000

int main(void)
{
	double x, y;
	unsigned long long k;
	double pi;

	srand(time(NULL));

	k = 0;
	for (unsigned long long i = 0; i < N; ++i) {
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		if (sqrt(pow(x, 2) + pow(y, 2)) < 1)
			++k;
	}

	pi = 4. * k / N;
	printf("%f\n", pi);

	return 0;
}
