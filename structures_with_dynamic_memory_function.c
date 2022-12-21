#include <stdio.h>
#include <stdlib.h>

struct PERSON {
	char name[32];
	int no;
};

int main(void)
{
	struct PERSON *per;

	if ((per = (struct PERSON *)malloc(sizeof(struct PERSON))) == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per->name, "Selen Salman");
	per->no = 162;

	printf("%s, %d\n", per->name, per->no);

	free(per);

	return 0;
}

--------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>

struct PERSON {
	char name[32];
	int no;
};

struct PERSON *get_person(void)
{
	struct PERSON *per;

	if ((per = (struct PERSON *)malloc(sizeof(struct PERSON))) == NULL)
		return NULL;

	printf("Adi soyadi:");
	gets(per->name);
	printf("No:");
	scanf("%d", &per->no);

	while (getchar() != '\n')
		;

	return per;
}

int main(void)
{
	struct PERSON *per;

	if ((per = get_person()) == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	printf("%s, %d\n", per->name, per->no);

	free(per);

	return 0;
}
