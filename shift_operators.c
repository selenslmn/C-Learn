// There are two shift operators in C: shift left (<< operator) and shift right (>> operator). 
// The translation operators are between arithmetic operators and comparison operators in terms of precedence.
// In translation operators, the left operand specifies the value to be shifted, and the right operand specifies the amount to be shifted.

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x6D;     /* 0110 1101 = 0x6D */
    unsigned char b;

    b = a << 1;                 /* 1101 1010 = 0xDA */
    printf("%02X\n", b);       

    b = a >> 1;                 /* 0011 0110 = 0x36 */
    printf("%02X\n", b);        

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// When we shift a number to the left n times, we multiply that number by 2 to the nth.
// When we shift the number to the right n times, we divide the number by 2 to the nth.

// Rules for shifts in C standards:

/* -For left shift:
a) Shifting a negative integer to the left causes undefined behavior.
b) If the number is positive, but as a result of left shift, 
if the number does not stay within the bounds of the raised type of the left operand (ie information loss occurs), there is still undefined behavior.
c) There is no harm in shifting unsigned integer types to the left.

-For right shift:
a) There is no harm in shifting a signed positive number to the right.
b) In the right shift of a signed negative number, the leftmost feed can be made with 1 or 0. 
Doing it with 1 actually means that a negative number is negatively divided by 2. 
Doing it with 0 makes the number a large positive number.
c) There is no harm in shifting unsigned integer types to the right. */

// As a result, care should be taken when performing translation operations on signed numbers.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// find out if n.bit is 0 or 1

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t a = 0x12345678;
    int n, result;

    printf("Bit no:");
    scanf("%d", &n);

    result = a >> n & 1;
    printf("%d\n", result);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t a = 0xAF;
    uint8_t result;

    result = a >> 4 | a << 4;
    printf("%02X\n", result);			/* FA */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Suppose we have a two-byte unsigned integer. We can get the low significant and high bytes of it like this:

#include <stdio.h>
#include <stdint.h>

#define LOBYTE(w)   ((w) & 0xFF)
#define HIBYTE(w)   ((w) >> 8 & 0xFF)

int main(void)
{
    uint16_t w = 0x1234;
    uint8_t high, low;

    high = HIBYTE(w);
    low = LOBYTE(w);

    printf("%02X\n", high);			/* 12 */
    printf("%02X\n", low);			/* 34 */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The bit NOT operator is represented by ~. This operator makes 1s 0 and 0s 1 in a number.

#include <stdio.h>

int main(void)
{
    int a = 0;

    a = ~a;

    printf("%d\n", a);      /* -1 */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
