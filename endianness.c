// It is called "endianness" when the placement of integer type objects longer than one byte changes from processor to processor.
// In Intel processors, the low-significant byte of the number is placed at the low address. (little endian)
// In processors such as Power PC, SPARC, Alpha, the high-significant byte of the number is placed at the low address. (big endian)

/* For example:

	int a = 0x12345678;

	the bytes in Intel processors:

	78
	56
	34
	12

	PowerPC:

	12
	34
	56
	78

*/

// Some processors are designed to work in both endianness. (ARM processors)
// There is no performance difference between little edian and big endian design.
// There is no difference between the byte bits either. 
// There is a difference in the sequence of bytes relative to each other.
// For example when we get the address of an int object we always get the lowest address.

#include <stdio.h>

int main(void)
{
    int a = 0x12345678;
    unsigned char *pc;

    pc = (unsigned char *) &a;
    printf("%02X\n", *pc);      /* 78 if little endian, 12 if big endian */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
    int a = 0x12345678;
    unsigned short *ps;

    ps = (unsigned short *) &a;
    printf("%04X\n", *ps);      /*  0x5678 if little endian, 0x7856 if big endian */

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
    int a = 0x12345678;
    unsigned char *pc;

    pc = (unsigned char *) &a;
    
    for (int i = 0; i < 4; ++i)
        printf("%02X\n", pc[i]);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
