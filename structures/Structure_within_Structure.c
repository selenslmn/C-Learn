// When declaring a structure, 
// After curly brace if the semicolon is not put and a variable list is written, 
// both the structure is declared and objects of that structure type are defined.
// Variables defined here can also be given an initial value.
// Caution: A struct cannot have an element of its own type!

//Below are 4 alternative examples of nested struct objects.

#include <stdio.h>

struct DATE {
	int day, month, year;
} date = {10, 12, 2009}, *pdate = &date;

int main(void)
{
	struct POINT {
		int x, y;
	} pt = {10, 20};

	printf("%d/%d/%d\n", date.day, date.month, date.year);
	printf("%d/%d/%d\n", pdate->day, pdate->month, pdate->year);

	printf("%d, %d\n", pt.x, pt.y);

	return 0;
}

/*-----------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

struct DATE {
	int day, month, year;
};

struct PERSON {
	char name[32];
	int no;
	struct DATE bdate;
};

int main(void)
{
	struct PERSON per;

	strcpy(per.name, "Selen Salman");
	per.no = 162;
	per.bdate.day = 20;
	per.bdate.month = 7;
	per.bdate.year= 1997;

	printf("%s, %d, %d/%d/%d\n", per.name, per.no, per.bdate.day, per.bdate.month, per.bdate.year);

	return 0;
}

/*--------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

struct DATE {
	int day, month, year;
};

struct PERSON {
	char name[32];
	int no;
	struct DATE bdate;
};

int main(void)
{
	struct PERSON per = {"Selen Salman", 162, {20, 7, 1997}};

	printf("%s, %d, %d/%d/%d\n", per.name, per.no, per.bdate.day, per.bdate.month, per.bdate.year);

	return 0;
}

/*--------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

struct DATE {
	int day, month, year;
};

struct PERSON {
	char name[32];
	int no;
	struct DATE bdate;
};


void disp(struct PERSON *pper)
{
	printf("%s, %d, %d/%d/%d\n", pper->name, pper->no, pper->bdate.day, pper->bdate.month, pper->bdate.year);
}

int main(void)
{
	struct PERSON per = {"Selen Salman", 162, {20, 7, 1997}};
	
	disp(&per);

	return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

struct DATE {
	int day, month, year;
};

struct PERSON {
	char name[32];
	int no;
	struct DATE bdate;
};

int main(void)
{
	struct PERSON per = {"Selen Salman", .bdate.day = 20, .bdate.month = 7, .bdate.year = 1997, .no = 162};
		
	printf("%s, %d, %d/%d/%d\n", per.name, per.no, per.bdate.day, per.bdate.month, per.bdate.year);

	return 0;
}
