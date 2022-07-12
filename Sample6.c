#include <stdio.h>

main(void)
{
	double a = 12.346;

	printf("___%10.2f___\n", a);		  /*___     12.35___*/
	printf("___%-10.2f___\n", a);		  /*___12.35     ___*/
	printf("___%.10f___\n", a);			  /*___12.3460000000___*/
	printf("___%.0f___\n", a);			  /*___12___*/

	return 0;
}
