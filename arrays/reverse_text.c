// Reverse text inside a char array

#include <stdio.h>

int main(void)
{  
    char s[] = "istanbul";
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        ;

    for (--i; i >= 0; --i)
        putchar(s[i]);                          /* lubnatsi */
    putchar('\n');

    return 0;
}

-----------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
    char s[100] = "ankara";
    int n;
    char temp;

    for (n = 0; s[n] != '\0'; ++n)
        ;

    for (int i = 0; i < n / 2; ++i) {
        temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }

    for (int i = 0; s[i] != '\0'; ++i)
        putchar(s[i]);                            /* arakna */
    putchar('\n');

    return 0;
}
