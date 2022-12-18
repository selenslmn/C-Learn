// Array names specify addresses but not objects. 
// The name of a struct array specifies the starting address of that struct, that is, the address of the first element. 
// However, we cannot increase this name with the ++ operator.

#include <stdio.h>

struct CITY {
	char name[32];
	int plate;
};

int main(void)
{
	struct CITY cities[5] = {
		{"Ankara", 6}, 
		{"Izmir", 35}, 
		{"Eskisehir", 26}, 
		{"Kutahya", 43}, 
		{"Istanbul", 34}
	};
	
	for (int i = 0; i < 5; ++i)
		printf("%s, %d\n", cities[i].name, cities[i].plate);

	return 0;
}

-------------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

struct CITY {
	char name[32];
	int plate;
};

int main(void)
{
	struct CITY cities[5] = {
		{"Ankara", 6}, 
		{"Izmir", 35}, 
		{"Eskisehir", 26}, 
		{"Kutahya", 43}, 
		{"Istanbul", 34}
	};
	struct CITY *pc;

	pc = cities;

	printf("%s, %d\n", pc->name, pc->plate);
	
	++pc;

	printf("%s, %d\n", pc->name, pc->plate);

	return 0;
}

----------------------------------------------------------------------------------------------
  
#include <stdio.h>

struct CITY {
	char name[32];
	int plate;
};

int main(void)
{
	struct CITY cities[5] = {
		{"Ankara", 6}, 
		{"Izmir", 35}, 
		{"Eskisehir", 26}, 
		{"Kutahya", 43}, 
		{"Istanbul", 34}
	};
	
	printf("%s, %d\n", cities->name, cities->plate);
	printf("%s, %d\n", (cities + 1)->name, (cities + 1)->plate);
	
	return 0;
}
