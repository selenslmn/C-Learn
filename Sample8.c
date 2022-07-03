#include <stdio.h>

main(void)
{
	double a;

	a = 123.456e5;
	printf("%f\n", a);			/* 12345600.000000 */

	a = 1.23e-5;
	printf("%f\n", a);			/* 0.000012 */

	a = 1e20;
	printf("%f\n", a);			/* 100000000000000000000.000000 */

	return 0;
}