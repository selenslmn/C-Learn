#include <stdio.h>

struct SAMPLE {
	int a;
	long b;
	double c;
};

int main(void)
{
	struct SAMPLE s = {10, 12, 14.25};
	struct SAMPLE *ps;

	ps = &s;

	printf("%d\n", (*ps).a);
	printf("%ld\n", (*ps).b);
	printf("%f\n", (*ps).c);

	return 0;
}

-----------------------------------------------------------------------
  
#include <stdio.h>

struct COMPLEX {
	double real;
	double imag;
};

int main(void)
{
	struct COMPLEX z = {5, 3};
	struct COMPLEX *pz;

	pz = &z;

	printf("%f+%fi\n", (*pz).real, (*pz).imag);

	return 0;
}
  
