// The function set_alarm calls the function given at a certain time. (Callback Function Example)

#include <stdio.h>
#include <time.h>

void set_alarm(time_t target, void (*pf)(void))
{
    time_t t;

    for (;;) {
        t = time(NULL);
        if (t == target) {
            pf();
            break;
        }
    }
}

void foo(void)
{
    printf("Ok\n");
}

int main(void)
{
    time_t t;

    t = time(NULL) + 10;

    set_alarm(t, foo);

    printf("continues..\n");
      
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Callback function can make changes when it is called with the addresses of the series elements.

#include <stdio.h>

enum EVENTS {
    FOREACH_PROGRESS, FOREACH_END
};

void for_each(int *pi, size_t size, void (*pf)(int *, int status))
{
    size_t i;

    for (i = 0; i < size - 1; ++i)
        pf(&pi[i], FOREACH_PROGRESS);

    pf(&pi[i], FOREACH_END);
}

void disp(int *pi, int status)
{
    printf("%d", *pi);
        
    putchar(status == FOREACH_PROGRESS ? ' ' : '\n');
}

void square(int *pi)
{
    *pi = *pi * *pi;
}

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};

    for_each(a, 5, disp);
    for_each (a, 5, square);
    for_each(a, 5, disp);


    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The Atexit function stores the functions given to it. When the program ends, he calls them "reverse order".
// The function returns to the value 0 in case of success and to a value other than zero in case of failure.
// The only reason the function fails is to register a large number of functions.

#include <stdio.h>
#include <stdlib.h>

void foo(void)
{
    printf("foo\n");
}

void bar(void)
{
    printf("bar\n");
}

int main(void)
{
    atexit(foo);
    atexit(bar);

    printf("main ends...\n");

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
