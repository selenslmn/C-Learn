#include <stdio.h>

int main(void)
{
	int x = 10, y = 20;

	printf("x= %d, y = %d\n", x,y);

	printf("x= %d, y = %d\n", x + 2, y);

	printf("%d%d\n", x, y);

	printf("%dx%d\n", x, y);

	printf("%d-%d\n", x, y);

	printf("%d\n%d", x, y);

	printf("%d\n%d\n", x, y);
	
	return 0;
}