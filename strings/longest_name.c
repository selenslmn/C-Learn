// to find the longest name

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *names[] = {"ali", "veli", "selami", "suleyman", "fatih", "ayse", NULL};
	size_t max_index, max_length, length;

	max_index = 0;
	max_length = strlen(names[0]);

	for (int i = 1; names[i] != NULL; ++i) {
		length = strlen(names[i]);
		if (length > max_length) {
			max_index = i;
			max_length = length;
		}
	}

	puts(names[max_index]);

	return 0;
}
