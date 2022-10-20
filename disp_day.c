#include <stdio.h>

#define isleap(year)	((year) % 4 == 0 && (year) % 100 != 0 || (year) % 400 == 0 ) 			

long total_days(int day, int month, int year)
{
	      long tdays = 0;

	      for (int i = 1900; i < year; ++i)
		            tdays += isleap(i) ? 366 : 365;

	      switch (month - 1) {
	              case 12:			        /* unreachable */
		                    tdays += 31;
	              case 11:
		                    tdays += 30;
	              case 10:
	                     	tdays += 31;
	              case 9:
		                   tdays += 30;
	              case 8:
		                   tdays += 31;
	              case 7:
		                   tdays += 31;
	              case 6:
		                   tdays += 30;
	              case 5:
	                     tdays += 31;
	              case 4:
		                   tdays += 30;
	              case 3:
		                   tdays += 31;
	              case 2:
		                   tdays += isleap(year) ? 29 : 28;
	              case 1:
		                   tdays += 31;
	      }

	      tdays += day;

	      return tdays;
}

void disp_day(int day, int month, int year)
{
	      long tdays;

	      tdays = total_days(day, month, year);

	      switch (tdays % 7) {
	              case 0:
		                    printf("Pazar\n");
		                    break;
	              case 1:
		                    printf("Pazartesi\n");
		                    break;
	              case 2:
		                    printf("Sali\n");
		                    break;
	              case 3:
		                    printf("Carsamba\n");
		                    break;
	              case 4:
		                    printf("Persembe\n");
	                    	break;
	              case 5:
		                    printf("Cuma\n");
		                    break;
	              case 6:
		                    printf("Cumartesi\n");
		                    break;
	      }
}

int main(void)
{
	      disp_day(20, 7, 1997);          /* Pazar */

	      return 0;
}
