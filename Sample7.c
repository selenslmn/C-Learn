#include <stdio.h>

main(void)
{
	int a;

	a = 100;
	printf("%d\n", a);		/* 100 */

	a = 0x64;
	printf("%d\n", a);		/* 100 */

	a = 012;
	printf("%d\n", a);		/* 10 */

	return 0;
}