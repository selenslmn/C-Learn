#include <stdio.h>
#include <string.h>

int main(void)
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[10];
	double c[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
	double d[10];

	memcpy(b, a, 40);				            /* unconditionally copy n bytes from one address to another address */

	for (int i = 0; i < 10; ++i)
		printf("%d ", b[i]);
		printf("\n");
	
	memcpy(d, c, 80);		              /* int 4 byte, double 8 byte */

	for (int i = 0; i < 10; ++i)
		printf("%f ", d[i]);
	printf("\n");

	return 0;
}

-------------------------------------------------------------------------------------------------------------

#include <stdio.h>

void *mymemcpy(void *dest, void *source, size_t n)		        /* if we write the memcpy function ourselves */
{
	char *pcdest = (char *)dest;		
	char *pcsource = (char *)source;	

	for (size_t i = 0; i < n; ++i)
		pcdest[i] = pcsource[i];

	return dest;
}

int main(void)
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[10];

	mymemcpy(b, a, 40);

	for (int i = 0; i < 10; ++i)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}

-------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "ankara";
	char d[100];

	memcpy(d, s, strlen(s) + 1);          /* The "+1" here is required to copy null character. */
	puts(d);

	return 0;
}

-------------------------------------------------------------------------------------------------------------
	
#include <stdio.h>
#include <string.h>

void insert(int *pi, size_t size, size_t index, int val)
{
	memmove(pi + index + 1, pi + index, (size - index) * 4);	        /* array expansion and shrink operation */
	pi[index] = val;
}

int main(void)
{
	int a[100] = {1, 2, 3, 4, 5};

	insert(a, 5, 0, 100); 		
										
	for (int i = 0; i < 6; ++i)	
		printf("%d ", a[i]);		      /* 100 1 2 3 4 5 */
	printf("\n");

	return 0;
}

--------------------------------------------------------------------------------------------------------------------
  
