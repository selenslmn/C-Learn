// In probability and statistics, states that as a sample size grows, its mean gets closer to the average of the whole population.
// This is due to the sample being more representative of the population as the sample become larger.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRYNUM		100000000

int main(void)
{
	unsigned long long head, tail;
	int val;
	double head_ratio, tail_ratio;

	srand(time(NULL));

	head = tail = 0;
	for (unsigned long long i = 0; i < TRYNUM; ++i) {
		val = rand() % 2;
		if (val == 0)			/* Head */
			++head;
		else
			++tail;				/* tail */
	}

	head_ratio = (double)head / TRYNUM;
	tail_ratio = (double)tail / TRYNUM;

	printf("head: %.8f, tail: %.8f\n", head_ratio, tail_ratio);

	return 0;
}
