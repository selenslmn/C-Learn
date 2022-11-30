#include <stdio.h>

int main(void)
{
	int x = 10, y = 20, z = 30;
	int *a[3];

	a[0] = &x;
	a[1] = &y;
	a[2] = &z;

	for (int i = 0; i < 3; ++i)
		printf("%d\n", *a[i]);

	return 0;
}

-------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int x[5] = {1, 2, 3, 4, 5}, y[5] = {6, 7, 8, 9, 10}, z[5] = {11, 12, 13, 14, 15};
	int *a[3] = {x, y, z};

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 5; ++k)
			printf("%d ", a[i][k]);
		printf("\n");
	}

	return 0;
}

--------------------------------------------------------------------------------------------
 
#include <stdio.h>

int main(void)
{
	char *names[3] = {"ali", "veli", "selami"};

	for (int i = 0; i < 3; ++i)
		puts(names[i]);

	return 0;
}
