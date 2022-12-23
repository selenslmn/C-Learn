// (*ps).a = ps->a (arrow operator)

#include <stdio.h>

struct DATE {
	int day, month, year;
};

int main(void)
{
	struct DATE d = {10, 12, 2009};
	struct DATE *pd;

	pd = &d;

	printf("%d/%d/%d\n", pd->day, pd->month, pd->year);

	return 0;
}

--------------------------------------------------------------------
  
#include <stdio.h>

struct CITY {
	char name[32];
	int plate;
};

int main(void)
{
	struct CITY c = {"Ankara", 6};
	struct CITY *pc = &c;

	putchar(pc->name[2]);		/* k */

	return 0;
}
