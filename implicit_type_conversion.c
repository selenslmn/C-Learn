#include <stdio.h>

int main(void)
{
		int a = 0x12345678;
		unsigned short b;

		b = a;

		printf("%x\n", b);		/* 5678 */

		return 0;
}

----------------------------------------------------
  
int main(void)
{
		int a = 56732683;			/* 0x0361AC0B */
		unsigned short b;

		b = a;

		printf("%u\n", b);		/* 0xAC0B = 44043 */

		return 0;
}

-----------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
		int a = 56732683;		/* 0361AC0B */
		short b;

		b = a;

		printf("%d\n", b);		/* 0xAC0B = -21493 */

		return 0;
}

---------------------------------------------------------
  
