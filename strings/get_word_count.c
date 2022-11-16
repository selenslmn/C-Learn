#include <stdio.h>
#include <string.h>

int get_word_count(char* text)
{
    int count = 0;

    for (;;) {
        while (*text != '\0' && strchr(";!.,?-*()/ ", *text) != NULL)
            ++text;
        if (*text == '\0')
            break;
        ++count;
        while (strchr(";!.,?-*()/ ", *text) == NULL)
            ++text;

        if (*text == '\0')
            break;
    }

    return count;
}

int main(void)
{
    char s[] = ";;;;;;   the weather is fine today! very nice...Yes ,,, yes 789 . Do you think Selen ?   ";
    int result;

    result = get_word_count(s);  /* 14 */
    printf("%d\n", result);

    return 0;
}
