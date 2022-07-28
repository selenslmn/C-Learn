
#include <stdio.h>

int main(void)
{
	int result;

	result = 1 + 2 < 3 + 4;
	printf("%d\n", result);		    /* 1 */

	result = 1 + (2 < 3) + 4;
	printf("%d\n", result);		    /* 6 */

	return 0;
}

--------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a, b;
	int result;

	a = 1;
	b = 3;
	result = a > 10 && ++b > 2;

	printf("result = %d, b = %d\n", result, b);		    /* result = 0, b = 3 */

	a = 20;
	b = 3;
	result = a > 10 && ++b > 2;

	printf("result = %d, b = %d\n", result, b);		    /* result = 1, b = 4 */

	return 0;
}

------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a = 2;

	a *= 2 * 3;		

	printf("%d\n", a);		/* 12 */
	
	return 0;
}

------------------------------------------------------------------------------
  
include <stdio.h>

int main(void)
{
	int a, b, c;

	c = (a = 10, b = 20);
	printf("a = %d, b = %d, c = %d\n", a, b, c);		/* a = 10, b = 20, c = 20 */
	
	return 0;
}
