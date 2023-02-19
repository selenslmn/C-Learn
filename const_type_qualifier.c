// const and volatile are type qualifiers.

// Const: It is invalid to assign values to const objects other than assign first values.

  const int a = 10;		/* valid */
	...
	a = 20;					/* invalid! */

/*----------------------------------------*/

  const int a[] = {1, 2, 3, ,4, 5};

	a[2] = /* invalid! */
    
/*----------------------------------------*/
    
    struct DATE {
		int day;
		int month;
		int year;  
	  };
	  ...
    const struct DATE date = {10, 12, 2007};      /* valid */
    
    date.month = 10;        					  /* invalid! all parts of the object are const */

/*--------------------------------------------------------------------------------------------------*/

  struct DATE {
		int day;
		const int month;
		int year;  
	};
	...
	struct DATE date = {10, 12, 2007};      /* valid */
		
	date.day = 21;          /* valid */
	date.year = 2009;       /* valid */
	date.month = 7;         /* invalid! */

/*--------------------------------------------------------------------------------------------------*/
  const int const a = 10;		/* valid but insignificant */
/*--------------------------------------------------------------------------------------------------*/
  const int g_size = 10;
	int g_a[g_size];		/* invalid! */
/*--------------------------------------------------------------------------------------------------*/
    int a[100];
    const int *pi;
    
    pi = &a[0];    /* valid, pi is not const */
    pi = &a[1]     /* valid, pi is not const */
    
    *pi = 100;      /* invalid! *pi is const */
    pi[20] = 100;  /* invalid! */
/*--------------------------------------------------------------------------------------------------*/
  const int *pi; = 	int const *pi;
/*--------------------------------------------------------------------------------------------------*/
  int a, b;
	int * const pi = &a;
	
	*pi = 10;            /* valid, *pi not const! */
	printf("%d\n", a);   /* 10 */

	pi = &b;            /* invalid! pi is const */
/*--------------------------------------------------------------------------------------------------*/
  int * const pi = &a, x, y;      /* pi is but x and y are not const */
/*--------------------------------------------------------------------------------------------------*/
  int a;
	const int * const pi = &a;     /* both pi and where it points are const */
/*--------------------------------------------------------------------------------------------------*/
  int a;
  const int * const pi = &a, b = 20;    /* pi, where it points and b are const */    
/*--------------------------------------------------------------------------------------------------*/ 
	const char s[] = "ankara";

	myputs(s);		/* invalid */

	/* BUT */
	
	void myputs(const char *str);

	const char s[] = "ankara";

	myputs(s);		/* valid */
/*--------------------------------------------------------------------------------------------------*/ 
	char *strcpy(char *dest, const char *source);

	char *strchr(const char *str, int ch);

	double mean(const double *pd, size_t size);

	void getdate(struct DATE *pdate);
	void setdate(const DATE *pdate);
/*--------------------------------------------------------------------------------------------------*/ 

#include <stdio.h>

typedef const int *PI;

int main()
{
    int a = 10, b = 20;
    PI pi = &a;

    pi = &b;        /* valid, where pi points are const */
    printf("%d\n", *pi);
    *pi = 20;       /* invalid! where pi points are const! */

    return 0;
}

/*--------------------------------------------------------------------------------------------------*/ 
