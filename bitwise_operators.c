// These operators process reciprocal bits of numbers. Such bitwise operations are used extensively in system programming.

/*	~	(Bit NOT)
	  &	(bit AND) 
  	^	(Bit EXOR)
	  |	(bit OR)
	  <<	(shift left)
	  >>	(shift right)  */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The & operator performs an "AND" operation on the corresponding bits of numbers. Automatic type conversion is applied before the operation.

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x3F;     /* 0011 1111 */
    unsigned char b = 0x77;     /* 0111 0111 */
    unsigned char c;

    c = a & b;                  /* 0011 0111  = 0x37 */
    printf("%02X\n", c);        /* 37 */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// find the n.bit of a number

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x3F;     /* 0011 1111 */

    if (a & 0x20)
        printf("5. Bit 1\n");
    else
        printf("5. Bit 0\n");

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// To make 0 the nth bit of a number without touching the other bits

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x3F;     /* 0011 1111 */

    a = a & 0xEF;
    printf("%02X\n", a);        /* 0010 1111 = 0x2F */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
