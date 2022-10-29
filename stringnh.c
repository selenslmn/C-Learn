// There are also n versions of the strcpy, strcat, and strcmp functions. These are named strncpy, strncat, and strncmp.

#include <stdio.h>
#include <string.h>

int main(void)
{
	char d[] = "yenisehir";
	char s[] = "eskihisar";

	strncpy(d, s, 4);             /* copying a certain number of characters of a text into an array */

	puts(d);		/* eskisehir */

	return 0;
}

--------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

char *mystrncpy(char *dest, char *source, size_t n);

int main(void)
{
	char d[1024] = "yenisehir";
	char s[] = "eski";

	mystrncpy(d, s, 10);

	puts(d);		/* eskisehir */

	return 0;
}

char *mystrncpy(char *dest, char *source, size_t n)           /* if we write the strncpy function ourselves */
{
	size_t i;

	for (i = 0; i < n && source[i] != '\0'; ++i)
		dest[i] = source[i];

	for (; i < n; ++i)
		dest[i] = '\0';

	return dest;
}

--------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <string.h>

int main(void)
{
	char d[1024] = "eski";
	char s[] = "hisarustu";

	strncat(d, s, 5);                     /* adding the first n characters of another text to the end of a text */

	puts(d);		/* eskihisar */

	return 0;
}

------------------------------------------------------------------------------------------------------------------------
 
 #include <stdio.h>

char *mystrncat(char *dest, char *source, size_t n);

int main(void)
{
	char d[1024] = "eski";
	char s[] = "hisarustu";

	mystrncat(d, s, 5);

	puts(d);		/* eskihisar */

	return 0;
}

char *mystrncat(char *dest, char *source, size_t n)               /* if we write the strncat function ourselves */
{
	size_t i, k;

	for (i = 0; dest[i] != '\0'; ++i)
		;

	for (k = 0; k < n && source[k] != '\0'; ++k)
		dest[i + k] = source[k];
	dest[i + k] = '\0';

	return dest;
}
 
-----------------------------------------------------------------------------------------------------------------------------
  
 #include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[] = "eskis";
	char s2[] = "eskihisar";
	int result;

	result = strncmp(s1, s2, 4);                /* comparing the first n characters of two texts */

	if (result > 0)
		printf("s1 > s2\n");
	else if (result < 0)
		printf("s1 < s2\n");
	else
		printf("s1 == s2\n");

	return 0;
}
