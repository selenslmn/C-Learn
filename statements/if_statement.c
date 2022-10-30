#include <stdio.h>

int main(void)
{
	int a;

	printf("Bir deger giriniz:");
	scanf("%d", &a);

	if (a > 0)
		printf("pozitif\n");
	else if (a < 0)
		printf("negatif\n");
	else
		printf("sifir\n");

	return 0;
}

---------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>

void disp_roots(double a, double b, double c)		  /* ax ^ 2 + bx + c = 0 (ikinci dereceden bir bilinmeyenli denklem) */
{
	double delta;
	double x1, x2;

	delta = b * b - 4 * a * c;						  /* denklemin diskriminantı */
	if (delta >= 0) {
		x1 = (-b + sqrt(delta)) / (2 * a);		/* 1.gerçek(reel) kök */
		x2 = (-b - sqrt(delta)) / (2 * a);		/* 2.gerçek(reel) kök */

		printf("x1 = %f, x2 = %f\n", x1, x2);
	}
	else
		printf("Gercek kok yok!..\n");
}

int main(void)
{
	double a, b, c;

	printf("a:");
	scanf("%lf", &a);

	printf("b:");
	scanf("%lf", &b);

	printf("c:");
	scanf("%lf", &c);

	disp_roots(a, b, c);

	return 0;
}
