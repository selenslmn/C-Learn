// There is a set of standard C functions whose prototypes start with str, which processes text in <string.h>.

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "ankara";
	size_t result;

	result = strlen(s);           /* the length of the text */
	printf("%zd\n", result);		/* 6 */

	return 0;
}

----------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

size_t mystrlen(char *str)                  /* if we write the function ourselves */
{
	size_t i;

	for (i = 0; str[i] != '\0'; ++i)
		;

	return i;
}

int main(void)
{
	char s[] = "ankara";		
	size_t result;

	result = mystrlen(s);
	printf("%zd\n", result);		/* 6 */

	return 0;
}

------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "ankara";
	char d[1024];

	strcpy(d, s);                 /* copies text from a char array to another array */

	puts(d);		                  /* ankara */

	return 0;
}

-----------------------------------------------------------------------------------------------------
  
#include <stdio.h>

char *mystrcpy(char *dest, char *source);

int main(void)
{
	char s[] = "ankara";
	char d[1024];

	mystrcpy(d, s);
	printf("%s\n", d);

	return 0;
}

char *mystrcpy(char *dest, char *source)
{
	for (size_t i = 0; (dest[i] = source[i]) != '\0'; ++i)            /* if we write the function ourselves */
		;

	return dest;
}

--------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "ankara";
	char d[1024];

	strcpy(d, s + 2);
	printf("%s\n", d);	      /* kara */

	return 0;
}

-----------------------------------------------------
  
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "ankara";
	char d[1024] = "istanbul";

	strcat(d, s);                         /* add another text to the end of a text */

	puts(d);		    /* istanbulankara */

	return 0;
}

--------------------------------------------------------------------------------------------
  
#include <stdio.h>

char *mystrcat(char *dest, char *source);

int main(void)
{
	char s[] = "ankara";
	char d[1024] = "istanbul";

	mystrcat(d, s);

	puts(d);		/* istanbulankara */

	return 0;
}

char *mystrcat(char *dest, char *source)                                  /* if we write the function ourselves */
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		;
	for (size_t k = 0; (dest[i + k] = source[k]) != '\0'; ++k)
		;

	return dest;
}

-----------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

char *mystrcat(char *dest, char *source)          /* if we write the function ourselves */
{
	strcpy(strchr(dest, '\0'), source);

	return dest;
}

int main(void)
{
	char s[] = "ankara";
	char d[1024] = "istanbul";
	
	mystrcat(d, s);
	puts(d);

	return 0;
}

------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "ankara";
	char *str;

	str = strchr(s, 'k');                             /* searching for a character in a text */
	if (str != NULL)
		printf("%s\n", str);		/* kara */
	else 
		printf("cannot find!");

	return 0;
}

---------------------------------------------------------------------------------------------------------------

#include <stdio.h>

char *mystrchr(char *str, int ch);

int main(void)
{
	char s[] = "ankara";
	char *str;
	
	str = mystrchr(s, 'k');
	puts(str);			/* kara */

	return 0;
}

char *mystrchr(char *str, int ch)      /* if we write the function ourselves */
{
	while (*str != '\0') {
		if (*str == ch)
			return str;
		++str;
	}

	return ch == '\0' ? str : NULL;
}

------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "izmir";
	char *str;

	str = strrchr(s, 'i');
	if (str)
		puts(str);		                /* ir */
	else
		printf("cannt find!..\n");

	return 0;
} 
  
------------------------------------------------------------------------------------------------------  

#include <stdio.h>
#include <string.h>

int main(void)
{
	char path[] = "/home/selen/study/test.c";
	char *fname;

	fname = strrchr(path, '/');
	if (fname)
		puts(fname + 1);

	return 0;
}  
  
-----------------------------------------------------------------------------------------------------  
  
#include <stdio.h>
#include <string.h>

char *mystrrchr(char *str, int ch);

int main(void)
{
	char path[4096];
	char *fname;

	printf("Bir yol ifadesi giriniz:");
	gets(path);

	if ((fname = mystrrchr(path, '/')) != NULL)
		puts(fname + 1);
	else
		puts(path);

	return 0;
}

char *mystrrchr(char *str, int ch)               /* if we write the function ourselves */
{
	char *result = NULL;

	while (*str != '\0') {
		if (*str == ch)
			result = str;
		++str;
	}

	return ch == '\0' ? str : result;	
}

--------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main(void)
{
	char passwd[] = "bluemoon";
	char s[1024];

	printf("Enter password:");
	gets(s);

	if (!strcmp(s, passwd))				/* compare two posts */
		printf("Ok\n");
	else
		printf("Incorrect password!..\n");

	return 0;
}	

----------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main(void)
{
	char passwd[] = "bluemoon";
	char s[1024];
	int i;

	for (i = 0; i < 3; ++i) {
		printf("Enter password:");
		gets(s);
		if (!strcmp(s, passwd)) 
			break;
		printf("Incorrect password!..\n");
	}

	if (i == 3)
		printf("Sorry you must wait 5 minutes to try again...\n");
	else
		printf("Ok\n");

	return 0;
}

----------------------------------------------------------------------------------------
	
#include <stdio.h>

int mystrcmp(char *s1, char *s2);

int main(void)
{
	char passwd[] = "maviay";
	char s[1024];

	printf("Enter password:");
	gets(s);

	if (!mystrcmp(s, passwd))
		printf("Ok\n");
	else
		printf("Incorrect password!..\n");

	return 0;
}

int mystrcmp(char *s1, char *s2)			/* if we write the function ourselves */
{
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		++s1;
		++s2;
	}
	return *s1 - *s2;
}
