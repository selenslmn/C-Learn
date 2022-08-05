#include <stdio.h>

int main(void)
{
	int i;

	i = 0;
	while (i < 10) {
		printf("%d\n", i);      /* 0'dan 10'a kadar (10 dahil değil) sayılar ekrana yazdırılmaktadır. */
		++i;
	}

	return 0;
}

---------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int i;

	i = 10;
	while (i) {
		printf("%d\n", i);      /* 10'dan başlanarak 0'a kadar (0 dahil değil) sayılar ekrana yazdırılmaktadır. */
		--i;
	}

	return 0;
}

---------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int i, n, total;

	printf("Bir sayi giriniz:");
	scanf("%d", &n);

	i = 1;
	total = 0;
	while (i <= n) {
		total += i;
		++i;
	}
	printf("%d\n", total);            /* 1'den n'e kadar olan sayıların toplamı */

	return 0;
}

---------------------------------------------------------------------------------------------------------------------
  

#include <stdio.h>

int main(void)
{
	int i;

	i = 0;
	while (++i < 10)
		printf("%d\n", i);      /* 1,2,...,9 */

	return 0;
}

------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int i;

	i = 0;
	while (i++ < 10)
		printf("%d\n", i);      /* 1,2,...,10 */

	return 0;
}

------------------------------------------------------

#include <stdio.h>

int main(void)
{
	int i;

	i = 0;
	do {
		printf("%d\n", i);      /* 0,1,...,9 */
		++i;
	} while (i < 10);

	return 0;
}

------------------------------------------------------
  
#include <stdio.h>

void clear_stdin(void)
{
	while (getchar() != '\n')             
		;
}

int main(void)
{
	int ch;

	do {
		printf("(e)vet/(h)ayir?");                      /* kullanıcıdan 'e' ya da 'h' ile bir seçim yapması istenmiştir. */
		ch = getchar();                                 /* Eğer kullanıcı 'e' ya da 'h' den birini girmemişse aynı soru yinelenmiş */
		if (ch != '\n')                                 /*  Kullanıcı bu karakterlerden birini girmeye zorlanmıştır. */        
			clear_stdin();                                /* tampon temizleme */
	} while (ch != 'e' && ch != 'h');

	if (ch == 'e')
		printf("evet\n");
	else
		printf("hayir\n");

	return 0;
}
