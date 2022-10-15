#include <stdio.h>

int main(void)
{
	int result;

	result = 'a';                     

	printf("%c, %d\n", result, result);		/* a, 97 (ASCII) */

	return 0;
}

---------------------------------------------------------------

#include <stdio.h>

int main(void)
{
	int a;

	a = 48;

	putchar(a);		/* int türden bir değerin karakter numarasını verir */ 
	putchar('\n');
	putchar('?');	

	return 0;
}

---------------------------------------------------------------

#include <stdio.h>

int main(void)
{
	int ch;

	ch = getchar();
	putchar(ch);
	putchar('\n');
	printf("ch %d, ch = %c\n", ch, ch); /* Bir sayı girdikten sonra o sayının ASCII tablosundaki değeri */

	return 0;
}
