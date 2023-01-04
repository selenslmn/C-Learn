// Typedef is used very often with structs. This way the programmer doesn't have to use the "struct" keyword.
/* What is the benefit of the typedef declaration?
1) The typedef declaration can be used to shorten type names.
2) The typedef declaration is used to ensure portability. For example, let's write a library. There is a kind of int in some systems, long in some systems. 
It would be more appropriate for the programmer to use the typedef name so that the programmer is not affected by this.
3) The typedef declaration can also be used to improve readability. Given names can make the code more meaningful.
*/

// If the same typedef is made a second time in C, this is considered invalid. However, it is considered valid in C++.

typedef struct tagDATE {
		int day, month, year;
	} DATE;

	DATE s;

/*------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

struct DATE {
	int day, month, year;
};

typedef struct DATE DT;

int main(void)
{
	DT d = {10, 12, 1990};

	printf("%d/%d/%d\n", d.day, d.month, d.year);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------*/

struct SAMPLE {
		int a;
		double b;
	};

	typedef struct SAMPLE SMP;

	struct SAMPLE s;
	SMP k;                           /* Here s and k are of the same type. The SMP type name means for struct SAMPLE entirely. */ 

/*------------------------------------------------------------------------------------------------------------------------------*/

typedef int I, *PI;

	PI pi;

	pi = (PI)malloc(sizeof(I) * 10);	        /* Here I stands for "int" type and PI stands for "int *" type. 
                                                Of course, since "int *" is equivalent to PI, so is "I *". */ 
