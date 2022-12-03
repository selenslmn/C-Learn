// There are two standard C functions for random number generation: rand and srand. Prototypes of these functions are declared in <stdlib.h>.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("%d\n", RAND_MAX);  /* 32767 in Microsoft compilers, 2147438647 in gcc compilers */
  
	return 0;
}

-------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int val;

	for (int i = 0; i < 20; ++i) {
		val = rand() % 10;                      /* we apply a mod operation to the value obtained from the rand function 
                                                    due to obtain random numbers in a narrower range. */
		printf("%d ", val);
	}
	printf("\n");

	return 0;
}

------------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>

	int main(void)
	{
		int val;

		srand(123456);                      /* The seed value can be changed with the srand function. */

		for (int i = 0; i < 20; ++i) {
			val = rand() % 10;
			printf("%d ", val);
		}
		printf("\n");

		return 0;
 	} 

---------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(void)
	{
		int val;

		srand(time(NULL));                              /* to obtain a different set of random numbers in each run */

		for (int i = 0; i < 20; ++i) {
			val = rand() % 10;
			printf("%d ", val);
		}
		printf("\n");

		return 0;
	}

---------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NPERSONS	5

int main(void)
{
	int index;
	char *names[] = {"ali", "veli", "selami", "ayse", "fatma"};

	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		index = rand() % NPERSONS;                            /* Random people were selected among 5 people */
		printf("%s\n", names[index]);
	}

	return 0;
}

---------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int val;
	char *names[5] = {"ali", "veli", "selami", "ayse", "fatma"};
	char *temp;

	srand(time(NULL));

	val = rand() % 5;
	temp = names[val];
	names[val] = names[4];
	names[4] = temp;
	
	val = rand() % 4;
	temp = names[val];
	names[val] = names[3];
	names[3] = temp;

	printf("%s %s\n", names[3], names[4]);		/* Picking 2 people randomly from 5 people */
	
	return 0;
}
 
