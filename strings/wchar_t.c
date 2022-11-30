// In C, wide characters are represented by type wchar_t and are in <stddef.h>.

#include <stdio.h>
#include <stddef.h>

int main(void)
{
	wchar_t ch;

	ch = L'ş';
	printf("%llu\n", (unsigned long long)ch);		/* 351 i.e. UNICODE UTF-16 'ş' */

	return 0;
}

------------------------------------------------------------------------------------------
/*  wchar_t s[] = L"ağrı dağı";
    wchar_t *str;

    str = L"ağrı dağı";      
*/
------------------------------------------------------------------------------------------

// In C, UNICODE UTF-16 and UNICODE UTF-32 characters are represented by <uchar.h>.

#include <stdio.h>
#include <uchar.h>

int main(void)
{
	char16_t x = u'ş';		/* UNICODE UTF-16 */
	char32_t y = U'ş';		/* UNICODE UTF-16 */

	printf("%llu\n", (unsigned long long)x);		/* 351 */
	printf("%llu\n", (unsigned long long)y);		/* 351 */

	return 0;
}

----------------------------------------------------------------------------------------------

/*  char16_t s[] = u"ağı dağı";
	  char16_t *k = u"ağrı dağı";
	  char32_t m[] = U"ağı dağı";
	  char32_t *r = U"ağrı dağı";
*/

----------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <uchar.h>

int main(void)
{
	char16_t s[] = u"ağrı";
		
	printf("%zd\n", sizeof(s));		/* 10 */
	
	return 0;
}

----------------------------------------------------------------------------------------------
  
