\\ One of the most used preprocessor commands is the #define command.
  
#include <stdio.h>

#define MAX_VAL		(10 + 20)

int main(void)
{
	int a;

	a = MAX_VAL * 2;		                  /* a = (10 + 20) * 2 = 60*/

	printf("%d\n", a);

	return 0;
}

-----------------------------------------------------------------------------
  
#include <stdio.h>

#define MAX_VAL		10 + 20

int main(void)
{
	int a;

	a = MAX_VAL * 2;		              /* a = 10 + 20 * 2 */

	printf("%d\n", a);		            /* 50 */

	return 0;
}

---------------------------------------------------------------------------------
  
#include <stdio.h>

#define CMD_DEL		1
#define CMD_DIR		2
#define CMD_COPY	3
...

switch (a) {
	case CMD_DEL:
			 break;
	case CMD_DIR:
			break;
	case CMD_COPY:
			break;
}

----------------------------------------------------------------------
  
#include <stdio.h>

	#define MAX		100

	int main(void)
	{
		printf("MAX");		  /* MAX */

		return 0;
	}

------------------------------------------------------------------------------
  
 #include <stdio.h>

	#define MSG		"Success\n"

	int main(void)
	{
		printf("MSG");		   /* MSG */
		printf(MSG);		    /* Success */

		return 0;
	}

----------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int a;

	a = EOF;				          /* EOF <stdio.h> içerisinde define edilmiş */
	printf("%d\n", a);

	a = BUFSIZ;				        /* BUFSIZ <stdio.h> içerisinde define edilmiş */
	printf("%d\n", a);

	return 0;
}

--------------------------------------------------------------------------------------------
  
#include <stdio.h>

#define IN

void foo(IN int a)
{
	printf("%d\n", a);
}

int main(void)
{
	IN IN
		IN

		IN
	foo(10);

	IN
	return 0;
}

----------------------------------------------------------------------------------------
  
#include <stdio.h>

#define square(a)		((a) * (a))

int main(void)
{
	int result;

	result = square(10 - 2);		          /* result = ((10 - 2) * (10 - 2)); */
	printf("%d\n", result);

	return 0;
}
