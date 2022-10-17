/*---------------------------------------------------------------------------------------------------------------------------------------------------

The functions that operate on single-byte characters are defined in ctype.h header file.

  isupper			checks whether the operand is an uppercase
	islower			checks whether the operand is lowercase
	isalpha			checks whether the operand is alphabetic
	isalnum			checks whether the operand is alphanumeric
	isdigit			checks whether the operand is a digit
	isxdigit		checks whether the operand is hexadecimal
	isspace			checks whether the operand is space
	ispunct			checks whether the operand is punctuation
	isascii			Is it one of the first 128 characters of the ASCII table?
	iscntrl			checks whether the operand is a control character (The first 32 characters of the ASCII table are control characters.)

----------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;

	printf("Bir karakter giriniz:");
	ch = getchar();

	if (isupper(ch))
		printf("upper case\n");
	else if (islower(ch))
		printf("lower case\n");
	else if (isdigit(ch))
		printf("digit\n");
	else if (isspace(ch))
		printf("white space char\n");
	else
		printf("another character\n");

	return 0;
}

---------------------------------------------------------
  
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;

	printf("Bir karakter giriniz:");
	ch = getchar();

	ch = toupper(ch);
	putchar(ch);

	return 0;
}

--------------------------------------------------------
  
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;

	printf("(e)vet/(h)ayir?\n");
	ch = getchar();
	ch = tolower(ch);

	if (ch == 'e')                                          /* case insensitive */
		printf("evet\n");
	else if (ch == 'h')
		printf("hayir\n");
	else
		printf("e ya da h girilmedi!\n");

	return 0;
}

-------------------------------------------------------------------------------------------
  
#include <stdio.h>

int mytoupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')           /* toupper function */
		return ch - 'a' + 'A';

	return ch;
}

int main(void)
{
	char ch;

	ch = getchar();
	ch = mytoupper(ch);

	putchar(ch);

	return 0;
}
