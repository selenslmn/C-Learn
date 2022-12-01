// to print a three-digit number into a char array as string with use sprintf

#include <stdio.h>
#include <math.h>

void num2text(int number, char *buf)
{
	char *ones[] = {"", "bir", "iki", "uc", "dort", "bes", "alti", "yedi", "sekiz", "dokuz"};
	char *tens[] = {"", "on", "yirmi", "otuz", "kirk", "elli", "altmis", "yetmis", "seksen", "doksan"};
	int one, ten, hundred;
	int index = 0;

	if (number == 0) {
		strcpy(buf, "sifir");
		return;
	}

	one = number % 10;
	ten = number / 10 % 10;
	hundred = number / 100;

	if (hundred > 0) {
		if (hundred != 1)
			index += sprintf(buf + index, "%s ", ones[hundred]);
		index += sprintf(buf + index, "yuz");
	}
	if (ten > 0) {
		if (hundred > 0)
			buf[index++] = ' ';
		index += sprintf(buf + index, "%s", tens[ten]);
	}
	if (one > 0) {
		if (number > 10)
			buf[index++] = ' ';
		index += sprintf(buf + index, "%s", ones[one]);
	}
}

int main(void)
{
	int number;
	char str[1024];

	for (;;) {
		printf("En fazla 3 basamakli bir sayi giriniz:");
		scanf("%d", &number);
		if (number == -1)
			break;
		if ((int)log10(number) + 1 > 3) {
			printf("sayi 3 basamaktan buyuk!\n");
			continue;
		}

		num2text(number, str);
		printf(":%s:\n", str);
	}

	return 0;
}
