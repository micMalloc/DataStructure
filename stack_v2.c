#include <stdio.h>
#include <stdlib.h>

//Implementation by Linked-List
struct NODE
{
	int key;
	struct NODE* next;
	struct NODE* prev;
};

struct NODE* findLoca();
void linkNodes (struct NODE*);
int pop();
void push(int, struct NODE*);
int isEmpty();
struct NODE* isFull();
void PrintStack();
void Free();

struct NODE* head = NULL;
struct NODE* top = NULL;

int main ()
{
	int menu, key;
	struct NODE* newNode = NULL;

	head = (struct NODE*)malloc(1 * sizeof(struct NODE));
	head->prev = head->next = NULL; 
	top = head;

	while (1)
	{
		scanf("%d", &menu);
		if (menu == 1)
		{
			scanf("%d", &key);
			newNode = isFull();
			if (newNode != NULL)
				push(key, newNode);
			else
				printf("Can not allocate new node, it's full\n");
		}
		else if (menu == 2)
		{
			if(!isEmpty())
				printf("%d\n", pop());
			else
				printf("Stack is empty\n");
		}
		else if (menu == 3)
		{
			PrintStack();
		}
		else if (menu == 4)
			break;
		else
			printf("Please Enter a valid key\n");
	}

	Free();
	return 0;
}
struct NODE* findLoca ()
{
	struct NODE* current = head;

	while (current->next != NULL)
		current = current->next;

	return current;
}
void linkNodes (struct NODE* newNode)
{
	struct NODE* loca;

	loca = findLoca();
	loca->next = newNode;
	newNode->prev = loca;
}

int pop()
{
	struct NODE* popNode;
	int popKey;
		
	popNode = top;
	popKey = top->key;
	top = top->prev;
	top->next = NULL;

	free(popNode);

	return popKey;
}

void push(int newKey, struct NODE* newNode)
{
	linkNodes(newNode);
	newNode->key = newKey;
	newNode->prev = top;
	newNode->next = NULL;

	top = newNode;
}

int isEmpty ()
{
	if (top == head)
		return 1;
	else
		return 0;
}
struct NODE* isFull ()
{
	struct NODE* newNode = NULL;
	newNode = (struct NODE*)malloc(1 * sizeof(struct NODE));

	return newNode;
}

void PrintStack ()
{
	struct NODE* current = head->next;

	while (current != NULL)
	{
		printf("%d\n", current->key);
		current = current->next;
	}
}

void Free ()
{
	struct NODE* prev = NULL;

	while (head != NULL)
	{
		prev = head;
		head = head->next;
		free(prev);
	}
}