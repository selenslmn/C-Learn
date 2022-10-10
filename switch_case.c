#include <stdio.h>

int main(void)
{
	int val;

	printf("Bir deger giriniz:");
	scanf("%d", &val);

	switch (val) {
		case 1:
			printf("bir\n");
			break;
		case 2:
			printf("iki\n");
			break;
		case 3:
			printf("üc\n");
			break;
		case 4:
			printf("dort\n");
			break;
		case 5:
			printf("bes\n");
			break;
		default:
			printf("hicbiri\n");
			break;
	}

	return 0;
}

------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int val;

	printf("Bir deger giriniz:");
	scanf("%d", &val);

	switch (val) {
	case 5:
		printf("bes\n");
		break;
	case 1:
		printf("bir\n");
		break;
	default:
		printf("hicbiri\n");
		break;
	case 2:
		printf("iki\n");
		break;

	case 4:
		printf("dort\n");
		break;
	case 3:
		printf("üc\n");
		break;
	}

	return 0;
}

---------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{
	int val;

	printf("Bir deger giriniz:");
	scanf("%d", &val);

	switch (val) {
		case 1:
			printf("bir\n");			// fallthrough
		case 2:
			printf("iki\n");			
			break;
		case 3:
			printf("üc\n");				// fallthrough
		case 4:
			printf("dort\n");
			break;
		case 5:
			printf("bes\n");
			break;
		default:
			printf("hicbiri\n");
			break;

	}

	return 0;
}

-----------------------------------------------------------------------------------------------------------

#include <stdio.h>

int get_command(void)
{
	int ch;

	while ((ch = getchar()) == ' ' || ch == '\t')
		;

	if (ch != '\n')
		while (getchar() != '\n')
			;

	return ch;
}

int main(void)
{
	int ch;

	for (;;) {
		printf("CSD>");

		ch = get_command();
		if (ch == '\n')
			continue;
		if (ch == 'q')
			break;

		switch (ch) {                                                       /* example of Command prompt with 'switch...case' */
			case 'e':
			case 'r':
				printf("remove command executes...\n");
				break;
			case 'c':
				printf("copy command executes...\n");
				break;
			case 'd':
				printf("dir command executes...\n");
				break;
			case 'm':
				printf("move command executes...\n");
				break;
			default:
				printf("invalid command: %c\n", ch);
				break;
		}
	}

	return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------------------
  
 #include <stdio.h>

int get_command(void)
{
	int ch;

	while ((ch = getchar()) == ' ' || ch == '\t')
		;

	if (ch != '\n')
		while (getchar() != '\n')
			;

	return ch;
}

void erase_command(void)
{
	printf("erase command executes...\n");                  /* Extending the case sections in switch statements breaks the readability. 
                                                              For this reason, if long operations are to be made in case sections, 
                                                                the functions that perform those operations should be defined. */
}

void copy_command(void)
{
	printf("copy command executes...\n");
}

void dir_command(void)
{
	printf("dircommand executes...\n");
}

void move_command(void)
{
	printf("move command executes...\n");
}

int main(void)
{
	int ch;

	for (;;) {
		printf("CSD>");

		ch = get_command();
		if (ch == '\n')
			continue;
		if (ch == 'q')
			break;

		switch (ch) {
			case 'e':
			case 'r':
				erase_command();
				break;
			case 'c':
				copy_command();
				break;
			case 'd':
				dir_command();
				break;
			case 'm':
				move_command();
				break;
			default:
				printf("invalid command: %c\n", ch);
				break;
		}
	}

	return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

int main(void)
{
	int a, b;

	printf("Bir deger giriniz:");
	scanf("%d", &a);

	switch (a) {
		case 1:
			printf("bir\n");
			printf("Bir deger daha giriniz:");
			scanf("%d", &b);
			if (b > 0) {
				case 2:
					printf("islemler devam ediyor..\n");
					break;
			}
			break;
		case 3:
			printf("uc\n");
			break;
		default:
			printf("default\n");
			break;
	}

	return 0;
}
