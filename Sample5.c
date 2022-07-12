#include <stdio.h>
#include <math.h>

main(void)
{
	int a = 10;
	int b = 7;
	int c = 121;
	int d = 1234567;

	printf("%-20d%f\n", a, sqrt(a));	/* 10       3.162278 */
	printf("%-20d%f\n", b, sqrt(b));	/* 7	    2.645751 */
	printf("%-20d%f\n", c, sqrt(c));	/* 121      11.000000 */
	printf("%-20d%f\n", d, sqrt(d));	/* 123456   1111.110706 */

	return 0;
}
