#include <stdio.h>

void clear_stdin(void)
{
	while (getchar() != '\n')               /* To Clear The Input Buffer */
		;
}

int main(void)
{
	int ch;

	for (int i = 0; i < 10; ++i) {
		for (int k = 0; k < 10; ++k) {
			printf("(%d, %d)\n", i, k);
			printf("Press ENTER to continue or q to exit:");
			ch = getchar();
			if (ch != '\n')
				clear_stdin();
			if (ch == 'q')
				break;
		}
		if (ch == 'q')
			break;
	}

	return 0;
}

-------------------------------------------------------------------------------------------
  
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
		printf("CSD>");                                         /* example of Command prompt with 'break' */

		ch = get_command();

		if (ch != '\n') {
			if (ch == 'q')
				break;
			if (ch == 'r')
				printf("remove command executes...\n");
			else if (ch == 'c')
				printf("copy command executes...\n");
			else if (ch == 'd')
				printf("dir command executes...\n");
			else if (ch == 'm')
				printf("move command executes...\n");
			else
				printf("invalid command: %c\n", ch);
		}
	}

	return 0;
}

-------------------------------------------------------------------------------------------------------------------------
  
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
			continue;                                                              /* example of Command prompt with 'continue' */
		
		if (ch == 'q')
			break;
		if (ch == 'r')
			printf("remove command executes...\n");
		else if (ch == 'c')
			printf("copy command executes...\n");
		else if (ch == 'd')
			printf("dir command executes...\n");
		else if (ch == 'm')
			printf("move command executes...\n");
		else
			printf("invalid command: %c\n", ch);
		
	}

	return 0;
}
