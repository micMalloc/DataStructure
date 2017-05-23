#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM 1001

void Insert (int);
int Delete ();
int isEmpty ();
int isFull ();
void PrintQueue ();

int queue[MAXIMUM];
int front, rear;

int main ()
{
	int menu, key;

	front = rear = -1;

	while (1)
	{
		printf("Please Enter the menu\n");
		scanf("%d", &menu);

		if (menu == 1)
		{
			scanf("%d", &key);
			if (!isFull())
				Insert(key);
			else
				printf("Queue is full\n");
		}
		else if (menu == 2)
		{
			if (!isEmpty())
				printf("Deleted Key : %d\n", Delete());
			else
				printf("Queue is empty\n");
		}
		else if (menu == 3)
			PrintQueue();
		else if (menu == 4)
			break;
		else
			printf("Re enter the menu\n");
	}

	return 0;
}

void Insert (int newKey)
{
	rear ++;
	queue[rear] = newKey;
}
int Delete ()
{
	int popKey;

	front ++;
	popKey = queue[front];
	return popKey;
}

int isEmpty ()
{
	if (front == rear)
		return 1;
	else
		return 0;
}
int isFull ()
{
	if (rear >= MAXIMUM)
		return 1;
	else
		return 0;
}

void PrintQueue ()
{
	int i;

	for (i = front + 1; i <= rear; ++ i)
		printf("%d\n", queue[i]);
}
/*
struct NODE
{
	int key;
	struct NODE* next;
};
typedef struct NODE* nodePtr;

void Insert(int, nodePtr);
int Delete();
int isEmpty();
nodePtr isFull();
void linkNodes(nodePtr);

nodePtr head = NULL;
nodePtr front, rear;

int main (void)
{
	nodePtr newNode;
	
	head = isFull();
	if (head == NULL)
		exit(1);
	else
	{
		head->next = NULL;
		front = rear = head;
	}
	

	return 0;
}

int isEmpty ()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

nodePtr isFull ()
{
	nodePtr newNode;

	newNode = (nodePtr)malloc(1 * sizeof(struct NODE));
	return newNode;
}

void Insert (int newKey, nodePtr newNode)
{
	if (rear == head)
	{
		head->next = newNode;
		newNode->next = NULL;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		newNode->next = NULL;
		rear = newNode;
	}
}

int Delete ()
{
	int deletedKey;
	
}*/