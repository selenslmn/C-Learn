// These N-bit integer types have emerged to ensure the portability of the code.
/* int8_t
	uint8_t
	int16_t
	uint16_t
	int32_t
	uint32_t
	int64_t
	uint64_t  */

#include <stdio.h>
#include <stdint.h>

struct SAMPLE {
  int32_t a;
  uint64_t b;
  uint32_t c;
};

int main(void)
{
	struct SAMPLE s;
  
  s.a = 10;
  s.b = 20;
  s.c = 40;

	return 0;
}

/*----------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
	intmax_t a = 12345678;      /* largest signed and unsigned integer types */

	printf("%jd\n", a);

	return 0;
}

/*----------------------------------------------------------------------------------------*/
