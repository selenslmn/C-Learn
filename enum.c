// The enum consists of variable names that specify constants. enum constants are always treated as constants of type int. For example:

	enum {Red, Green, Blue}; 	 /* Red, Green ve Blue are int */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

enum COLOR {
		Red, Green, Blue
	};
Blue = 10;	    /* invalid, because this operation is like 2 = 10  */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

// When declaring an enum, it is not mandatory to name the enum. For example:

enum { sunday, monday, tuesday, wednesday, thursday, friday, saturday};
enum { January, February, March, April, May, June, July, August, September, October, November, December};

/*-----------------------------------------------------------------------------------------------------------------------------------*/

enum COLOR {
		Red = 10, Green, Blue
	};                                                  /* Red = 10, Green = 11 ve Blue = 12 */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  enum { sunday, monday = 3, tuesday, wednesday, thursday = 7, friday, saturday};   /* sunday = 0, monday = 3, tuesday = 4, wednesday = 5, thursday = 7, friday = 8,... */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  // Enum constants can have the same value. For example:

	enum KEY { Enter = 1, Return = 1, Insert, Home, PgDown = 12, PgUp = 20};

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  enum COLOR {
		Red = 2147483646, Green, Blue			/* invalid! Blue exceeded int bounds! */
	};

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  // Enum constants can also take negative values:

	enum TEST {AA = -1, BB, CC};      /* AA = -1, BB = 0 ve CC = 1 */ 

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  enum TEST = {A = 'a', B = 'b', C = 'd'};		/* valid. Characters enclosed in single quotes are constants of type int. */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

	enum TEST = {A = "ankara", B = "izmir", C = "istanbul"};		/* invalid! We cannot value an enum constant with two quotes. */	 

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  #include <stdio.h>

	enum COLOR {
		Red, Green, Blue		/* enum constants can be used anywhere. */
	};

	int main(void)
	{
		int a = Red;		/* valid */

		return 0;
	}

	void foo(void)
	{
		int x = Red;		/* valid */
	}

/*-----------------------------------------------------------------------------------------------------------------------------------*/

	#include <stdio.h>

	int main(void)
	{
		enum COLOR {
			Red, Green, Blue
		};
	
		int a;

		a = Red;		/* valid, enum constants can also be used anywhere at the global level. */

		return 0;
	}

	void foo(void)
	{
		int x = Red;		/* invalid! However, it is not used locally. */
	}

/*-----------------------------------------------------------------------------------------------------------------------------------*/

// The address of an enum object cannot be directly assigned to a compatible integer pointer either.

	enum COLOR c = 123;
	int *pi;

	pi = &c;		/* invalid! */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

	enum COLOR *pc;       /* A pointer to enum type has no significant benefit. */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

	enum ColorSet1 {
		Red, Green, Blue		
	};

	enum ColorSet2 {
		Magenta, Yellow, Blue			/* invalid! */
	};

	int Magenta;						/* invalid! */

/*-----------------------------------------------------------------------------------------------------------------------------------*/
 
  // When give value to an enum constant, previous enum constants can be used.

	enum {Red, Green = Red + 2, Blue = Green +2};		/* valid */

/*-----------------------------------------------------------------------------------------------------------------------------------*/
  
  // Enum types can also be typedef.

	enum Color {
		Red, Green, Blue
	};

	typedef enum Color Cl;

	Cl c;		                              /* c is enum Color type */

/*-----------------------------------------------------------------------------------------------------------------------------------*/	

	enum Color {
		Red, Green, Blue
	} c, *pc;

	// c is object of enum Color type and pc is pointer of type enum Color. 

/*-----------------------------------------------------------------------------------------------------------------------------------*/
