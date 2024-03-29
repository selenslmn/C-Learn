#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int val;
	struct NODE *next;
};

struct LLIST {
	struct NODE *head;
	struct NODE *tail;
	size_t count;
};

struct LLIST *create_llist(void);
struct NODE *add_item_tail(struct LLIST *llist, int val);
struct NODE *add_item_head(struct LLIST *llist, int val);
void clear_llist(struct LLIST *llist);
void walk_llist(struct LLIST *llist);
void destroy_llist(struct LLIST *llist);
size_t count_llist(struct LLIST *llist);

int main(void)
{
	struct LLIST *llist;

	if ((llist = create_llist()) == NULL) {
		fprintf(stderr, "cannot create linked list!..\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 100; ++i)
		if (add_item_head(llist, i) == NULL) {
			fprintf(stderr, "cannot create node!...\n");
			exit(EXIT_FAILURE);
		}

	walk_llist(llist);

	destroy_llist(llist);

	return 0;
}

struct LLIST *create_llist(void)
{
	struct LLIST *llist;

	if ((llist = (struct LLIST *)malloc(sizeof(struct LLIST))) == NULL)
		return NULL;

	llist->head = NULL;
	llist->tail = NULL;
	llist->count = 0;

	return llist;
}

struct NODE *add_item_tail(struct LLIST *llist, int val)
{
	struct NODE *newnode;

	if ((newnode = (struct NODE *)malloc(sizeof(struct NODE))) == NULL)
		return NULL;
	newnode->val = val;
	newnode->next = NULL;

	if (llist->head == NULL)
		llist->head = newnode;
	else
		llist->tail->next = newnode;
	llist->tail = newnode;

	++llist->count;

	return newnode;
}

struct NODE *add_item_head(struct LLIST *llist, int val)
{
	struct NODE *newnode;

	if ((newnode = (struct NODE *)malloc(sizeof(struct NODE))) == NULL)
		return NULL;
	newnode->val = val;
	
	if (llist->head == NULL)
		llist->tail = newnode;

	newnode->next = llist->head;
	llist->head = newnode;

	++llist->count;

	return newnode;
}

void walk_llist(struct LLIST *llist)
{
	struct NODE *node;

	node = llist->head;

	while (node != NULL) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}

void clear_llist(struct LLIST *llist)
{
	struct NODE *node, *temp;

	node = llist->head;

	while (node != NULL) {
		temp = node->next;
		free(node);
		node = temp;
	}
	llist->head = NULL;
	llist->tail = NULL;
	llist->count = 0;
}

void destroy_llist(struct LLIST *llist)
{
	clear_llist(llist);
	free(llist);
}

size_t count_llist(struct LLIST *llist)
{
	return llist->count;
}
