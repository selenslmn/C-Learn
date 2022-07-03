#include <stdio.h>

int main(void)
{
	int a = 97;
	double b = 12.45;
	unsigned int c = 32503456;
	int d = 100;
	double e = 12000.345678;

	printf("%d - %c\n", a, a);		/* 97 - a */
	printf("%f\n", b);				/* 12.450000 */
	printf("%u\n", c);				/* 32503456 */
	printf("%x\n", d);				/* 64 */
	printf("%e\n", e);				/* 1.200035e+04 */

	return 0;
}