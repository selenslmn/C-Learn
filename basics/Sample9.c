#include <stdio.h>

int main(void)
{
	char ch;

	ch = '\\';
	printf("%c\n", ch);     /* / */

	return 0;
}

------------------------------------------------------------

#include <stdio.h>

int main(void)
{
	char ch;

	ch = '\'';
	printf("%c\n", ch);     /* ' */

	return 0;
}

------------------------------------------------------------

#include <stdio.h>

int main(void)
{
	printf("\"Ankara\"\n");       /* "Ankara" */

	return 0;
}

------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	printf("c:\temp\a.dat\n");		    /* yanlış yazım */
	printf("c:\\temp\\a.dat\n");		  /* doğru yazım */

	return 0;
}
