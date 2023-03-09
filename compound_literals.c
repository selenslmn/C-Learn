// Compound literals are a way of using structures and arrays practically in expressions.
// We can't apply type conversion to array type or struct type, but we can do it with composite constants. 
// The address of the composite constant can also be obtained immediately.

#include <stdio.h>

struct DATE {
    int day, month, year;
};

void disp_date(struct DATE *pdate)
{
    printf("%02d/%02d/%04d\n", pdate->day, pdate->month, pdate->year);
}

int main(void)
{
    struct DATE d;

    disp_date(&(struct DATE) { 29, 10, 1923 });

    d = (struct DATE){30, 08, 1922};
    disp_date(&d);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void disp(const int *pi, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        printf("%d ", pi[i]);
    printf("\n");
}

int main(void)
{
    disp((int[5]) { 10, 20, 30, 40, 50 }, 5);               /* The string length does not need to be specified. */
    
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The values of composite constants can be changed.

#include <stdio.h>

int main(void)
{
    int *pi;

    pi = (int[]){10, 20, 30};

    *pi = 100;       /* valid */

    for (int i = 0; i < 3; ++i)
        printf("%d\n", pi[i]);
    printf("\n");
    
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// In fact, composite constants can be created for normal types as well as arrays and structures.

	int *pi;
	...
	pi = &(int){10};		/* valid */

// We create an object of type int and assign its address to pi. Note that composite constants actually create an object, not a constant.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// "designated initializer" syntax can be used in composite constants.

#include <stdio.h>

int main(void)
{
    int *pi;
    
    pi = (int[10]){[5] = 100,[7] = 200, 300};

    for (int i = 0; i < 10; ++i)
        printf("%d \n", pi[i]);
    printf("\n");

    return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
