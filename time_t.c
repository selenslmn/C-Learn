#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t;

	t = time(NULL);

	printf("%.0Lf\n", (long double)t);          /* gives the number of seconds since 01.01.1970 */

	return 0;
}
