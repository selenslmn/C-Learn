#include <stdio.h>

int main(void)
{
	int i;

	i = 0;
REPEAT:
	printf("%d\n", i);                    /* An example of how the goto statement works, 
                                            but the goto statement should not be used to loop as in the example. */
	++i;
	if (i < 10)
		goto REPEAT;

	return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------
  
 #include <stdio.h>

int main(void)
{
	int ch;

	for (int i = 0; i < 10; ++i) {
		for (int k = 0; k < 10; ++k) {
			printf("(%d,%d)\n", i, k);
			printf("press q to exit:");
			ch = getchar();
			if (ch == 'q')
				goto EXIT;                                  /* exited inner loop with goto in one go */
			if (ch != '\n')
				while (getchar() != '\n')
					;
		}
	}

EXIT:
	return 0;
}

-----------------------------------------------------------------------------
  
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

		switch (ch) {
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
			case 'q':
				goto EXIT;
			default:
				printf("invalid command: %c\n", ch);
				break;
		}
	}
EXIT:
	return 0;
}
