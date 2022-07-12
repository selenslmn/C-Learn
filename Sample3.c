#include <stdio.h>

int main(void)
{
	int x = 10, y = 20;

	printf("x= %d, y = %d\n", x,y);			/* x= 10, y = 20 */

	printf("x= %d, y = %d\n", x + 2, y);		/* x= 12, y = 20 */

	printf("%d%d\n", x, y);				/* 1020 */

	printf("%dx%d\n", x, y);			/* 10x20 */

	printf("%d-%d\n", x, y);			/* 10-20 */

	printf("%d\n%d", x, y);				/* 10
                                                           20 */
	
	return 0;
}
