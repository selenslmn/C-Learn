#include <stdio.h>

int main(void)
{
		int a = 0x12345678;
		unsigned short b;

		b = a;

		printf("%x\n", b);		/* 5678 */

		return 0;
}

-----------------------------------------------------------------------------------
  
int main(void)
{
		int a = 56732683;			/* 0x0361AC0B */
		unsigned short b;

		b = a;

		printf("%u\n", b);		/* 0xAC0B = 44043 */

		return 0;
}

------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
		int a = 56732683;		/* 0361AC0B */
		short b;

		b = a;

		printf("%d\n", b);		/* 0xAC0B = -21493 */

		return 0;
}

---------------------------------------------------------------------------
  
#include <stdio.h>

	int main(void)
	{
		unsigned int a = 0xAB8254C2;
		int b;

		b = a;				

		printf("%u\n", b);		/* 0xFFFFFFFF = 4294967295 */

		return 0;
	}

--------------------------------------------------------------------------------------------
	
#include <stdio.h>

	int main(void)
	{
		signed char a = -1;
		unsigned int b;

		b = a;		

		printf("%u\n", b);		/* 4294967295 */

		return 0;
	}

-------------------------------------------------------------------------------
	
int main(void)
	{
		int a = -123;
		_Bool b;

		b = a;
		printf("%d\n", b);	/* 1 */

		return 0;
	}

---------------------------------------------------------------------------------
	
#include <stdio.h>

	int main(void)
	{
		unsigned int a = 1;
		signed char b = -1;
		unsigned int c;

		c = a * b;
		printf("%u\n", c);		/* 4294967295 */

		return 0;
	}

