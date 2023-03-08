// It is similar to structure but different data structures.

	union SAMPLE {
		int a;
		long b;
		double c;
	};

	union SAMPLE s;

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// s is of type "union SAMPLE". The elements of a union are again accessed with the dot operator, such as s.a, s.b and s.c. 
// There can be pointers of the Union type. Unity elements with a pointer can be accessed with the -> operator.

	union SAMPLE s;
	union SAMPLE *ps;

	ps = &s;

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// union types can also be typedef.

	typedef union tagSAMPLE {
		int a;
		long b;
		double c;
	} SAMPLE;

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Unit and structure with the same name cannot be declared in the same field of activity.

	union SAMPLE {
		/* ... */
	};

	struct SAMPLE {		          /* invalid! */
		/* ... */
	};

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// A unity object can given first value. However, only the first element of the union can given value. More than one element cannot given.

	union SAMPLE {
		int a;
		long b;
		double c;
	};

	union SAMPLE s = {1, 2, 3};		        /* invalid! */
	union SAMPLE k = {1};			            /* valid, value given to element a */
	union SAMPLE s = {.c = 1};			      /* valid! */
	union SAMPLE k = {.b = 1, 2};		      /* invalid! */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Unions are rarely used in C.
// The only major difference between unions and structs is the placement of elements.
// Elements of a union are placed coincidentally.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The largest element of this union is of type double (8 bytes). 8 bytes will be reserved for this unity object.
// The first byte of these 8 bytes will be element a, the first 2 bytes will be element b, the first 4 bytes will be element c, and the first 8 bytes will be element d.
	
#include <stdio.h>

	union SAMPLE {
		char a;
		short b;
		int c;
		double d;
	};

	int main(void)
	{
		union SAMPLE s;

		printf("%zd\n", sizeof(s));		      /* 8, "16" if it was a struct instead of a union. */

		return 0;
	}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Units are used because it's providing space.
// Units can also be used to form the whole from the parts and to divide the whole into parts.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// An element of the union by making struct, we placed 4 bytes of information in the dword element and obtained them one by one from the bytes element of the union. 
// Then we did the reverse of this process.

#include <stdio.h>
#include <stdint.h>

struct BYTES {
	uint8_t b0;
	uint8_t b1;
	uint8_t b2;
	uint8_t b3;
};

union DWORD {
	uint32_t dword;
	struct BYTES bytes;
};

int main(void)
{
	union DWORD dw;

	dw.dword = 0x12345678;

	printf("%02x %02X %02X %02X\n", dw.bytes.b0, dw.bytes.b1, dw.bytes.b2, dw.bytes.b3);	      /* 78 56 34 12 */

	dw.bytes.b0 = 0x10;
	dw.bytes.b1 = 0x20;
	dw.bytes.b2 = 0x30;
	dw.bytes.b3 = 0x40;

	printf("%08lx\n", (unsigned long)dw.dword);		      /* 40302010 */
	
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
