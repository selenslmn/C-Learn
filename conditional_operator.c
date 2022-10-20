result = val % 2 == 0 ? 100 : 200;    ->    if (val % 2 == 0)
		                                           result = 100;
	                                          else
		                                           result = 200;

---------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int val, result;

	printf("Bir degere giriniz:");
	scanf("%d", &val);

	printf(val % 2 == 0 ? "cift\n" : "tek\n");

	return 0;
}

----------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 100; ++i) 
		printf("%d%c", i, i % 5 == 4 ? '\n' : ' ');                 /* 0 1 2 3 4
	   	                                                             5 6 7 8 9
  return 0;                                                        10 11 12 13 14
}                                                                  ... */

----------------------------------------------------------------------------------
  
#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int result;

	result = max(3, 7);		        	/* 7 */
	printf("%d\n", result);
	
	return 0;
}
  
---------------------------------------------------------------------------------
  
#include <stdio.h>

#define MAX(a, b)		((a) > (b) ? (a) : (b))

int main(void)
{
	int result;

	result = MAX(3, 7);			          /* result = ((3) > (7) ? (3) : (7)) */
	printf("%d\n", result);		        /* 7 */
	
	return 0;
}
  
---------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int result;

	printf("a:");
	scanf("%d", &a);

	printf("b:");
	scanf("%d", &b);

	printf("c:");
	scanf("%d", &c);

	result = a > b ? (a > c ? a : c) : (b > c ? b : c);
	printf("%d\n", result);

	return 0;
}
  
-------------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a;
	int result;

	printf("Bir deger giriniz:");
	scanf("%d", &a);

	result = (a % 2 == 0 ? 100 : 200) + 300;
	printf("%d\n", result);

	return 0;
}
