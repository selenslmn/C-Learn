// A function that generates 6 distinct numbers between 1 and 49.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *get_lotto_column(int *col);

int main(void)
{
	int a[6];

	srand(time(NULL));

	get_lotto_column(a);

	for (int i = 0; i < 6; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void get_lotto_column(int *col)
{
	int val;
	int flag;

	for (int i = 0; i < 6; ++i) {		
		do {
			flag = 0;
			val = rand() % 49 + 1;
			for (int k = 0; k < i; ++k) {
				if (col[k] == val) {
					flag = 1;
					break;
				}
			}
		} while (flag);

		col[i] = val;
	}
	return col;
}
