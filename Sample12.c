#include <stdio.h>

int main(void)
{
	int a;

	a = 3;

	++a;						        /* a = a + 1 */;
	printf("%d\n", a);			/* 4 */

	a++;			
	printf("%d\n", a);			/* 5 */

	a = 3;

	--a;						        /* a = a - 1 */
	printf("%d\n", a);			/* 2 */

	a--;						
	printf("%d\n", a);			/* 1 */

	return 0;
}

-------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a, b;

	a = 3;

	b = ++a * 2;
	printf("a = %d, b = %d\n", a, b);		  /* a = 4, b = 8 */

	a = 3;

	b = a++ * 2;
	printf("a = %d, b = %d\n", a, b);		  /* a = 4, b = 6 */

	return 0;
}  

---------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a, b;

	a = 3;

	b = --a;
	printf("a = %d, b = %d\n", a, b);	    /* a = 2, b = 2 */

	a = 3;

	b = a--;		
	printf("a = %d, b = %d\n", a, b);	    /* a = 2, b = 3 */

	return 0;
}

----------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a, b, c;

	a = 3;
	b = 2;

	c = ++a * b--;
	printf("a = %d, b = %d, c = %d\n", a, b, c);		  /* a = 4, b = 1, c = 8 */
	
	return 0;
}
