// ppi is the pointer to the pointer. The type component of the pointer here is in the form "int *".

	int a = 10;
	int *pi;
	int **ppi;

	pi = &a;
	ppi = &pi; 

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  // We can assign the address of a pointer to a double-star pointer of the same type. 
  // Also, we can assign the address of a char pointer to ppc, not an int pointer.

	int *pi;
	char **ppc;

	ppc = &pi;		/* invalid! */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

	int a = 10;
	int *pi;
	int **ppi;
	int ***pppi;   /* not widely used. */

	pi = &a;
	ppi = &pi;
	pppi = &ppi;

/*-----------------------------------------------------------------------------------------------------------------------------------*/
  
  int x = 10, y = 20, z = 30;
	int *a[] = {&x, &y, &z};

	int **ppi;

	ppi = a;
	
  // The expression a is of type int ** and holds the starting address (address of the first element) of this pointer array.
  // Now *ppi specifies the first element of the array. This element is already a pointer of type int.
	 
/*-----------------------------------------------------------------------------------------------------------------------------------*/

	#include <stdio.h>

	int main(void)
	{
		int x = 10, y = 20, z = 30;
		int *a[] = {&x, &y, &z};
		int **ppi;

		ppi = a;
		for (int i = 0; i < 3; ++i)
			printf("%d\n", *ppi[i]);

		return 0;
	}

	// With the ppi[i] expression, we actually access the i.index element of the pointer array.

/*-----------------------------------------------------------------------------------------------------------------------------------*/

// If we want to pass an array of pointers to a function via parameter, the parameter of the function must be the pointer pointing to the pointer. 

#include <stdio.h>

void disp_names(char **names)
{
	for (size_t i = 0; names[i] != NULL; ++i)
		puts(names[i]);
}

int main(void)
{
	char *names[] = {"ali", "veli", "selami", "ayse", "fatma", NULL};

	disp_names(names);

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Let's write a function that can place an address inside a given pointer.
// alloc_intarray function dynamically allocates a certain length array and writes its address into the pointer. If the function fails, the program terminates.

#include <stdio.h>
#include <stdlib.h>

int *alloc_intarray(size_t size)
{
	int *pi;

	if ((pi = (int *)malloc(sizeof(int) * size)) == NULL) {
		fprintf(stderr, "cannot allocate array!..\n");
		exit(EXIT_FAILURE);
	}

	return pi;
}

int main(void)
{
	int *pi;

	pi = alloc_intarray(10);

	for (int i = 0; i < 10; ++i)
		pi[i] = i;

	for (int i = 0; i < 10; ++i)
		printf("%d ", pi[i]);
	printf("\n");

	free(pi);

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
