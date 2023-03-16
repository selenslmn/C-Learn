// The EXOR operation(^) is the operation that returns 0 if the operands are the same, and 1 if they are different. ("exclusive or")

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x5B;     /* 0101 1011 */
    unsigned char b = 0x7D;     /* 0111 1101 */
    unsigned char c;

    c = a ^ b;                  /* 0010 0110 */

    printf("%02X\n", c);        /* 26 */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// 0 is the neutral element in the EXOR operation. But 1 gives the reverse of the operation.
// Without touching the other bits of a number, we replace a certain bit of it with its inverse by putting it in the EXOR operation.
// Replace the 4th bit with its inverse without touching the other bits below:

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x6B;     /* 0110 1101 */
 
    a = a ^ 0x10;

    printf("%02X\n", a);        /* 0111 1011 = 0x7B */
    
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The EXOR operation is a reversible operation. Due to this feature, it is widely used in some areas such as encryption.

/*	a = 0110 1101
	  b = 1011 0010

	  a ^ b = 1101 1111 => c
	  c ^ a = 1011 0010 => b
	  c ^ b = 0110 1101 => a
                            */

// For example:

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x6D;     /* 0110 1101 */
    unsigned char b = 0xB2;     /* 0110 1111 */
    unsigned char c, d, e;

    c = a ^ b;
    printf("%02X\n", c);        /* 1011 1111 = 0xDF */

    d = c ^ a;
    printf("%02X\n", d);        /* 0110 1111 = 0xB2 */

    e = c ^ b;
    printf("%02X\n", e);        /* 0110 1101 = 0x6D */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
