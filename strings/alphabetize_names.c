// to alphabetize names with use bubble sort algorithm

#include <stdio.h>
#include <string.h>

#define SIZE		12

int main(void)
{
	char *names[SIZE] = {"ali", "veli", "selami", "suleyman", "fatih", "ayse", "salih", "burhan", "can", "sibel", "jale", "temel"};
	char *temp;
	int flag;
	size_t  i;

	i = 0;
	do {
		flag = 0;
		for (size_t k = 0; k < SIZE - 1 - i; ++k)
			if (strcmp(names[k], names[k + 1]) > 0) {
				temp = names[k];
				names[k] = names[k + 1];
				names[k + 1] = temp;
				flag = 1;
			}
		if (!flag)
			break;
		++i;
	} while (flag);

	for (size_t i = 0; i < SIZE; ++i)
		printf("%s ", names[i]);
	printf("\n");

	return 0;
}
