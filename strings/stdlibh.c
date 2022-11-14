/* There are three classic standard C functions that convert a string of numeric characters to int, long, and double. 
   The prototypes of the functions are located in the <stdlib.h> file.
   - atoi (alphabetic to int)
   - atol(alphabetic to long)
   - atof (alphabetic to floating point)  */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s[] = "123alex";
    int val;

    val = atoi(s);
    printf("%d\n", val);		/* 123 */
    
    return 0;
}

------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int myatoi(char *str)                                   /* if we write the atoi function ourselves */
{
    int total = 0;
    int sign = 1;

    while (isspace(*str))
        ++str;

    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        ++str;
    }

    while (isdigit(*str)) {
        total = total * 10 + *str - '0';
        ++str;
    }

    return sign * total;
}

int read_int(void)
{
    char s[4096];

    gets(s);

    return myatoi(s);
}

int main(void)
{
    int val;

    printf("Enter a number:");
    val = read_int();
    printf("%d\n", val);
    
    return 0;
}

-----------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int myatoi(char *str)                 /* We also used the above function with the [] operator instead of the * operator. */
{
    int total = 0;
    int sign = 1;
    size_t i;

    for (i = 0; isspace(str[i]); ++i)
        ;

    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -1;
        ++i;
    }

    for (; isdigit(str[i]); ++i) 
        total = total * 10 + str[i] - '0';

    return sign * total;
}

int read_int(void)
{
    char s[4096];

    gets(s);

    return myatoi(s);
}

int main(void)
{
    int val;

    printf("Enter a number:");
    val = read_int();
    printf("%d\n", val);
    
    return 0;
}

--------------------------------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
  
int read_int(void)
{
    char s[4096];

    gets(s);

    return atoi(s);
}

int main(void)
{
    int val;

    printf("Enter a number:");
    errno = 0;
    val = read_int();
    if (errno != 0)     /* or if (errno == ERANGE)*/
        printf("there is an overflow.");          /* when the numbers in the text exceed the limits of the relevant genre in negative or positive terms */
    else
        printf("%d\n", val);
    
    return 0;
}

------------------------------------------------------------------------------------------------------------------------
// There are also slightly more capable versions of the atoi, atol, atof and atoll functions. One of them is strtol.
  
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s[] = "    100    ";
    char k[] = " 0x100  ";
    long val;

    val = strtol(s, NULL, 10);                                    /* strtol converts the number in the string to the type long. */
    printf("%ld\n", val);           /* 100 */

    val = strtol(s, NULL, 2);
    printf("%ld\n", val);           /* 4 */

    val = strtol(k, NULL, 0);
    printf("%ld\n", val);           /* 256  */

    return 0;
}
