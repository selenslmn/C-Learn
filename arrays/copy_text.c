// Copying text from one array to another array

#include <stdio.h>

int main(void)
{
	char s[100];
	char d[100];
	
	printf("Enter a text: ");
	gets(s);

	for (int i = 0; (d[i] = s[i]) != '\0'; ++i)
		;

	puts(s);
	puts(d);

	return 0;
}
