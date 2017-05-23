#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
//Operations
void push(int);
int pop();
int isEmpty();
int isFull();
void PrintStack();

int stack[MAX];
int top = -1;

int main (void)
{
	int menu, key;
	
	while(1)
	{
		printf("Select the menu : \n");
		printf("1. Push a new key\n");
		printf("2. Pop a key in the Stack\n");
		printf("3. Print all key in the Stack\n");
		printf("4. Exit the program\n");
		
		scanf("%d", &menu);
		if (menu == 1)
		{
			printf("Type a new key to be stored in stack\n");
			scanf("%d", &key);
			if (!isFull())
				push(key);
			else
				printf("Stack is full\n");
		}
		else if (menu == 2)
		{
			if (!isEmpty())
				printf("Poped key : %d\n", pop());
			else
				printf("Stack is Empty\n");
		}
		else if (menu == 3)
			PrintStack();
		else if (menu == 4)
			break;
		else
			printf("Enter the valid menu key\n");
	}

	return 0;
}

void push(int newKey)
{
	top ++;
	stack[top] = newKey;
}
int pop()
{
	int popKey;

	popKey = stack[top];
	top --;

	return popKey;
}
int isEmpty()
{
	if (top < 0)
		return 1;
	else
		return 0;
}
int isFull()
{
	if (top >= MAX)
		return 1;
	else
		return 0;
}
void PrintStack()
{
	int i;

	for (i = 0; i <= top; ++ i)
		printf("%d\n", stack[i]);
}

/*
Implementation by Linked-List
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
}*/