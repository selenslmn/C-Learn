#include <stdio.h>
#include <stdlib.h>

void bar(void)
{
    printf("bar begins...\n");

    exit(EXIT_SUCCESS);

    printf("bar ends...\n");
}

void foo(void)
{
    printf("foo begins...\n");
    bar();
    printf("foo ends...\n");

}

int main(void)
{
    printf("main begins...\n");

    foo();
   
    printf("main ends...\n");


    return 0;
}
