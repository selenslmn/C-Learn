#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  clock_t start, stop;
  double result;
  
  start = clock();
  
  for (long long int i = 0; i < 10000000000; ++i)
    ;
  
  stop = clock();
  
  result = (double)(stop - start) / CLOCKS_PER_SEC;
  
  printf("%f\n", result);
  
  return 0;
  
}
