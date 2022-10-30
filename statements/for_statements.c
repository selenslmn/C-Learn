#include <stdio.h>

int main(void)
{
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d\n", i);          /* 0,1,...,9 */

	return 0;
}

-----------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int i;

	for (i = 0; i < 10; i += 2)
		printf("%d\n", i);          /* 0,2,...,8 */

	return 0;
}
  
-----------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int i;

	for (i = 10; i != 0; --i)
		printf("%d\n", i);        /* 10,9,...,1 */

	return 0;
}

-----------------------------------------------------

#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y;

	for (x = 0; x < 6.28; x += 0.1) {
		y = sin(x);
		printf("%f\t%f\n", x, y);           /* 0'dan 6.28'e kadar sayıların sinüs değerleri 0.1 artırımla yazdırılmaktadır */
	}

	return 0;

 -------------------------------------------------------------------------------------------------------------------------------
   
 #include <stdio.h>

int main(void)
{
	int n, total, i;

	printf("Bir sayi giriniz:");
	scanf("%d", &n);

	total = 0;
	for (i = 1; i <= n; ++i)
		total += i;

	printf("%d\n", total);        /* 1'den klavyeden girilen sayıya kadar sayıların toplamı hesaplanmaktadır */

	return 0;
}
  
-----------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <math.h>

int isprime(int val)
{
	int i;
	double val_sqrt;

	if (val % 2 == 0)
		return val == 2;

	val_sqrt = sqrt(val);
	for (i = 3; i <= val_sqrt; i += 2)      /* Öklit teoremi */ 
		if (val % i == 0)
			return 0;

	return 1;
}

int main(void)
{
	int i;

	for (i = 2; i < 1000; ++i)
		if (isprime(i))
			printf("%d ", i);         /* isprime fonksiyonundan faydalanılarak 2'den 1000'e kadar asal sayılar yan yana yazdrılmıştır. */
	printf("\n");

	return 0;
}
  
-------------------------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int n;
	int i, k;

	printf("Bir sayi giriniz:");
	scanf("%d", &n);

	for (i = 1; i <= n; ++i) {
		for (k = 0; k < i; ++k)		/* nested loop, print as many star patterns as the number of n */
			putchar('*');
		putchar('\n');
	}

	return 0;
}
