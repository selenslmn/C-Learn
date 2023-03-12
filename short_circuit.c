// The Bitwise “AND” and “OR” operators don’t have a short circuit behaviour but The logical operators have.
// bitwise operators can only be used with integer types.

#include <stdio.h>

int foo(void)
{
    printf("foo\n");

    return 0;
}

int bar(void)
{
    printf("bar\n");

    return 0x3F;
}

int tar(void)
{
    printf("tar\n");

    return 0x7A;
}

int main(void)
{
    int result;

    result = foo() & bar() & tar();

    printf("%d\n", result);			            /* foo bar tar */

    result = foo() && bar() && tar();

    printf("%d\n", result);			            /* 0 foo 0 */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// For bit OR operation | operator is used. This operator "OR" operation the reciprocal bits of the number.

#include <stdio.h>

int main(void)
{
    unsigned char a = 0xA2;         /* 1010 0010 */
    unsigned char b = 0x34;         /* 0011 0100 */
    unsigned char c;

    c = a | b;

    printf("%02X\n", c);            /* 1011 0110 = 0xB6 */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Without touching the other bits of a number, we can set the bit in a certain place to 1 with the bitwise OR operator.
// For example, making the 4th bit 1 without touching the other bits of the number in a:

#include <stdio.h>

int main(void)
{
    unsigned char a = 0xA7;       /* 1010 0111 */

    a = a | 0x10;				          /* 0001 0000 */
    printf("%02X\n", a);          /* 1011 0111 = 0xB7 */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// "Bit AND" operator takes precedence over "Bit OR" operator.
// In C, the comparison operators take precedence over the bit AND, OR, and EXOR operators.

#include <stdio.h>

int main(void)
{
    int a;

    printf("Enter a number:");
    scanf("%d", &a);

    if ((a & 1) == 0)			            /* need to use parentheses */
        printf("even\n");
    else
        printf("odd\n");

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
