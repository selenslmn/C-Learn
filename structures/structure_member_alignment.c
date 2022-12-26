// Here in common systems where the int type is 4 bytes, all objects are placed in multiples of four.

// Here, three bytes space are left after a and c to keep the b and c elements of the structure at a multiple of four.

#include <stdio.h>

	struct SAMPLE {
		char a;
		int b;
		char c;
		int d;
	};

	int main(void)
	{
		struct SAMPLE s;

		printf("%zd\n", sizeof s);			/* 16 */

		return 0;
	}

/*--------------------------------------------------------------------------------------------------------------------------------*/

// Objects of this structure type would take up less space if the programmer had organized the structure elements as follows:

#include <stdio.h>

	struct SAMPLE {
		char a;
		char b;
		int c;
		int d;
	};

	int main(void)
	{
		struct SAMPLE s;

		printf("%zd\n", sizeof s);		/* 12 */

		return 0;
	}

/*------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

	struct SAMPLE {
		int a;
		char b;
		int c;
		char d;
	};

	int main(void)
	{
		struct SAMPLE s;

		printf("%zd\n", sizeof s);		/* 16 */

		return 0;
	}

/*------------------------------------------------------------------------------------------------------------------------------------*/

// The #pragma pack(N) directive can be used in both Microsoft and gcc and clang compilers to change the alignment.

#include <stdio.h>

	#pragma pack(1)

	struct SAMPLE {
		char a;
		int b;
		char c;
		int d;
	};

	int main(void)
	{
		struct SAMPLE s;

		printf("%zd\n", sizeof s);		/* 10 */

		return 0;
	}

/*------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

	#pragma pack(1)

	struct SAMPLE {
		char a;
		int b;
		char c;
		int d;
	};

	#pragma pack(8)

	struct MAMPLE {
		char a;
		int b;
		char c;
		int d;
	};

	int main(void)
	{
		struct SAMPLE s;
		struct MAMPLE m;

		printf("%zd\n", sizeof s);		/* 10 */
		printf("%zd\n", sizeof m);		/* 16*/

		return 0;
	}

/*------------------------------------------------------------------------------------------------------------------------------------*/

// With the _Alignas(N) specifier we can place the int object in multiples of 8. 
// However, according to C11 standards, a high alignment cannot be converted to a low alignment with the _Alignas(N) specifier.

#include <stdio.h>

	struct SAMPLE {
		 int a;
		_Alignas(8) int b;
	};

	int main(void)
	{
		struct SAMPLE s;

		printf("%zd\n", sizeof s);		/* 16 */

		return 0;
	}
