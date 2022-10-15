#include <stdio.h>
#include <math.h>

int main(void)
{
	double val, result;

	printf("Bir deger giriniz:");
	scanf("%lf", &val);

	result = sqrt(val);
	printf("%f\n", result);         /* karakök */

	return 0;
}

----------------------------------------------
  
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, result;

	printf("Taban:");
	scanf("%lf", &a);

	printf("Us:");
	scanf("%lf", &b);

	result = pow(a, b);
	printf("%f\n", result);       /* üslü sayılar */

	return 0;
}

-------------------------------------------------------
  
#include <stdio.h>
#include <math.h>

int main(void)
{
	double result, radian;

	result = sin(3.141592653589793238462643 / 2);
	printf("%f\n", result);

	radian = asin(result);
	printf("%f\n", radian);

	return 0;
}

-------------------------------------------------------
  
#include <stdio.h>
#include <math.h>

int main(void)
{
	double result;

	result = round(3.6);
	printf("%f\n", result);		/* 4 */

	result = round(3.4);
	printf("%f\n", result);		/* 3 */

	return 0;
}

--------------------------------------------------------
  
#include <stdio.h>
#include <math.h>

int main(void)
{
	long result;

	result= lround(3.6);
	printf("%ld\n", result);		/* 4 */

	return 0;
}

--------------------------------------------------------
  
#include <stdio.h>
#include <math.h>

int main(void)
{
	double result;

	result= floor(3.9);
	printf("%f\n", result);		/* 3 */     /* floor: bir double sayıdan küçük yada eşit tam sayıyı double türden vermektedir */

	result = floor(-3.9);
	printf("%f\n", result);		/* -4 */

	result = ceil(3.1);
	printf("%f\n", result);		/* 4 */     /* ceil: bir double sayıdan büyük ya da ona eşit en yakın tamsayıyı double türden vermektedir */

	result = ceil(-3.1);
	printf("%f\n", result);		/* -3 */

	return 0;
}
