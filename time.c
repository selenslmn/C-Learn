#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t;
	char *str;

	t = time(NULL);
	str = ctime(&t);      /* Sun Feb  5 19:13:53 2023 */
	puts(str);

	return 0;
}

/*----------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t;
	char *str;

	t = time(NULL);
	str = asctime(localtime(&t));       /* same as ctime function, just different parameter */
	puts(str);

	return 0;
}

/*----------------------------------------------------------------------------------------------------------*/

// We can calculate the elapsed time between two dates with the "mktime" function.

#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now, eqwk, result;
	struct tm tm = {0};
	struct tm *pt;

	tm.tm_year = 97;
	tm.tm_mon = 7;
	tm.tm_mday = 20;
	tm.tm_isdst = -1;
	tm.tm_hour = 0;
	tm.tm_min = 40;
	tm.tm_sec = 0;

	now = time(NULL);
	eqwk = mktime(&tm);
	result = now - eqwk;
	
	pt = localtime(&result);

	printf("%d yıl, %d ay, %d gün, %d saat, %d dakika, %d saniye\n", pt->tm_year - 70, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec);
	
	return 0;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

int main(void)
{
	char buf[4096];
	time_t t;
	struct tm *pt;

	t = time(NULL);
	pt = localtime(&t);

	strftime(buf, 4096, "%a %b %d %H:%M:%S %Y", pt);                      /* same as ctime function, but creates in text format */

	puts(buf);

	return 0;
}
