// Two methods are used to pass a struct object to a function via parameter.
// 1) Passing a copy of the struct object to the function (bad technique)
// 2) Passing struct object to function via address (good technique)

#include <stdio.h>

struct SAMPLE {
	int a;
	int b;
	double c;
};

int main(void)
{
	struct SAMPLE s;
	struct SAMPLE* ps = &s;

	printf("%p\n", ps);				  /* 00000013524FF908 */
	printf("%p\n", &ps->a);			/* 00000013524FF908 */
	printf("%p\n", &ps->b);			/* 00000013524FF90C */
	printf("%p\n", &ps->c);			/* 00000013524FF910 */

	return 0;
}

----------------------------------------------------------------------------------------------------------------------------------
// In big data, this method is a waste of time and no change can be made in the object passed as a parameter in the function.
  
#include <stdio.h>

	struct SAMPLE {
		int a;
		int b;
		int c;
	};

	void foo(struct SAMPLE k)		/* k = s */
	{
		printf("%d, %d, %d\n", k.a, k.b, k.c);
	}

	int main(void)
	{
		struct SAMPLE s = {10, 20, 30};

		foo(s);			/* bad technique */

		return 0;
	}

---------------------------------------------------------------------------------------------------------------------------------------
// In this method, it is possible to change the elements of the object within the function, no matter how large the structure is.
  
#include <stdio.h>

	struct SAMPLE {
		int a;
		int b;
		int c;
	};

	void foo(struct SAMPLE *ps)				/* ps = &s */
	{
		printf("%d, %d, %d\n", ps->a, ps->b, ps->c);
	}

	int main(void)
	{
		struct SAMPLE s = {10, 20, 30};

		foo(&s);			/* good technique */

		return 0;
	}

----------------------------------------------------------------------------------------------
  
#include <stdio.h>

	struct SAMPLE {
		int a;
		int b;
		int c;
	};

	void set(struct SAMPLE *ps)				/* ps = &s */
	{
		ps->a = 100;
		ps->b = 200;
		ps->c = 300;
	}

	void disp(struct SAMPLE *ps)			/* ps = &s */
	{
		printf("%d, %d, %d\n", ps->a, ps->b, ps->c);
	}

	int main(void)
	{
		struct SAMPLE s = {10, 20, 30};

		disp(&s);
		set(&s);
		disp(&s);

		return 0;
	}

---------------------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

struct DATE {
	int day;
	int month;
	int year;
};

void disp_date(struct DATE *pd)
{
	printf("%d/%d/%d\n", pd->day, pd->month, pd->year);
}

void get_date(struct DATE *pd)
{
	printf("Day: ");
	scanf("%d", &pd->day);

	printf("Month: ");
	scanf("%d", &pd->month);

	printf("Year: ");
	scanf("%d", &pd->year);
}

int main(void)
{
	struct DATE date;

	get_date(&date);
	disp_date(&date);

	return 0;
}
