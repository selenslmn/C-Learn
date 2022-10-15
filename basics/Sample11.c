#include <stdio.h>

int main(void)
{
	double a;

	printf("Bir sayi giriniz:");
	scanf("%lf", &a);		  /* double %lf ile okunmalıdır */

	printf("%f\n", a);		/* printf fonksiyonunda %lf diye bir formak karakteri yoktur */

	return 0;
}

---------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	char ch;

	scanf("%c", &ch);     /* scanf ile biz getchar gibi karakter de okuyabiliriz */
	putchar(ch);

	return 0;
}
