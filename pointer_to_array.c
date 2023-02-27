  T (*p)[N];  

//	If there were no brackets, the p was state "demonstrator series":

	T *p[N];

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

	int (*pai)[5];      /* the whole series */

	int a[5];
	int (*pai)[5];
	int pi;

	pai = &a;	        /* valid */
	pi = a;		        /* valid */
	pi = &a;	        /* invalid! */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
	
  int a[5];
	int (*pai)[6];

	pai = &a;		      /* invalid! Must be the same length */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

	int (*pai)[];		  /* invalid! must not left empty */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

  int a[5];
	int (*pai)[5];

	pai = &a;		      /* valid */
	*pai = 10;		    /* invalid, *pai is not object */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
	
  int a[5] = {1, 2, 3, 4, 5};
	int (*pai)[5];
	int *pi;

	pai = &a;
	
	(*pai)[1] = 10;		                /* 1st index element of the series is updated */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
	
  int a[3][2];
	int (*pai)[2];

	pai = a;	            /* valid */ 

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int(*pai)[2];

	pai = a;

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", pai[i][k]);
		printf("\n");
	}

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* At least we have to know the column */

#include <stdio.h>

void disp_matrix(const int(*pai)[2], int size)   
{
	for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", pai[i][k]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};

	disp_matrix(a, 3);

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The only way to define a function that can take both matrix as a parameter is that the parameter of the function is a void demonstrator. 
// Then the appointment of this void demonstrator to an int demonstrator in the function 
// Finally, the memory organization of the matrix through this int demonstrator is known to access elements.

#include <stdio.h>

void disp_matrix(const void *pmatrix, size_t rowsize, size_t colsize)
{
	const int *pi = (const int *)pmatrix;

	for (size_t i = 0; i < rowsize; ++i) {
		for (size_t k = 0; k < colsize; ++k) 
			printf("%d ", pi[colsize * i + k]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int b[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

	disp_matrix(a, 3, 2);
	disp_matrix(b, 4, 3);

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Dynamic allocation can also be made for multi-dimensional series. */

#include <stdio.h>
#include <stdlib.h>

void disp_matrix(int **pmatrix, size_t rowsize, size_t colsize)
{
	const int *pi = (const int *)pmatrix;

	for (size_t i = 0; i < rowsize; ++i) {
		for (size_t k = 0; k < colsize; ++k) 
			printf("%d ", pi[colsize * i + k]);
		printf("\n");
	}
}

int main(void)
{
	int (*pai)[2];

	if ((pai = (int(*)[2]) malloc(sizeof(int) * 3 * 2)) == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 3; ++i) 
		for (int k = 0; k < 2; ++k)
			pai[i][k] = i + k;
		

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", pai[i][k]);
		printf("\n");
	}

	free(pai);
	
	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
