/* Expressing the time elapsed from a given origin as an integer */

#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t;

	t = time(NULL);

	printf("%.0Lf\n", (long double)t);          /* gives the number of seconds since 01.01.1970 */

	return 0;
}

/*--------------------------------------------------------------------------------------------------------------------*/

// In the example below, first the number of seconds elapsed from the epoch is found with the time function.
// And then converted into date-time information with the localtime function.

#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t;
	struct tm *pt;
	char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	t = time(NULL);
	pt = localtime(&t);

	printf("%02d/%02d/%04d %02d:%02d:%02d - %s\n", pt->tm_mday, pt->tm_mon + 1, pt->tm_year + 1900, pt->tm_hour, pt->tm_min, pt->tm_sec, days[pt->tm_wday]);

	return 0;
}
