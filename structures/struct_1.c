#include <stdio.h>

struct SAMPLE {
	int a[5];
	double b;
};

int main(void)
{
	struct SAMPLE s = {1, 2, 3, 4, 5, 3.14};

	for (int i = 0; i < 5; ++i)
		printf("%d ", s.a[i]);        /* 1 2 3 4 0 */
	printf("\n%f\n", s.b);          /* 3.140000 */

	return 0;
}

---------------------------------------------------------------
  
#include <stdio.h>

struct PERSON {
	char name[32];
	int no;
};

int main(void)
{
	struct PERSON per = {"Selen Salman", 123};

	printf("%s %d\n", per.name, per.no);

	return 0;
}

-------------------------------------------------------------------
  
#include <stdio.h>

struct PERSON {
	char *name;
	int no;
};

int main(void)
{
	struct PERSON per;

	per.name = "Selen Salman";				/* Assigning the address of a secure text to the name pointer */
	per.no = 123;
	printf("%s %d\n", per.name, per.no);

	return 0;
}

---------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

struct PERSON {
	char *name;
	int no;
};

int main(void)
{
	struct PERSON per = {"Selen Salman", 123};
	
	printf("%s %d\n", per.name, per.no);

	return 0;
}
