/* Data structures whose elements are sequentially in memory but can be of different types are called "structures". 
Structures and arrays are very similar to each other. Elements of both arrays and structures exist sequentially in memory. 
However, while array elements are all of the same type, struct elements can be of different types. 
Compilers can leave control spaces called "padding" between building elements. This is called "alignment". 
Alignment does not disturb the sequentiality of the structural elements. */

#include <stdio.h>

struct SAMPLE {
	int a;
	long b;
	double c;
};

int main(void)
{
	struct SAMPLE s;

	s.a = 10;
	s.b = 20;
	s.c = 30.2;

	printf("%d, %ld, %f\n", s.a, s.b, s.c);
	
	return 0;
}

------------------------------------------------------------------------
  
#include <stdio.h>

struct DATE {
	int day, month, year;
};

int main(void)
{
	struct DATE d;

	printf("%p\n", &d.day);
	printf("%p\n", &d.month);
	printf("%p\n", &d.year);
	
	return 0;
}

---------------------------------------------------------------------
  
#include <stdio.h>

struct SAMPLE {
	int a;
	long b;
	double c;
};

int main(void)
{
	struct SAMPLE s = {10};

	printf("%d, %ld, %f\n", s.a, s.b, s.c);		/* 10, 0, 0.000000 */

	return 0;
}

-------------------------------------------------------------------------
  
#include <stdio.h>

struct DATE {
	int day;
	int month;
	int year;
};

int main(void)
{
	struct DATE d = {10, 12, 1993};
	struct DATE k;

	k = d;                                /* Two structure objects can be assigned to each other, provided that they are of the same type. */

	printf("%d/%d/%d\n", k.day, k.month, k.year);		/* 10/12/1993 */

	return 0;
}

---------------------------------------------------------------------------
  
#include <stdio.h>
#include <string.h>

struct PERSON {
	char name[32];
	int no;
};

int main(void)
{
	struct PERSON per;

	strcpy(per.name, "Ali Serce");
	per.no = 123;

	printf("%s, %d\n", per.name, per.no);

	return 0;
}

  
