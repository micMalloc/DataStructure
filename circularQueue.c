#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int isEmpty ();
int isFull ();
void Insert (int);
int Delete ();
void Print ();

int queue[MAXSIZE];
int front, rear;

int main (void)
{
	int selNum, key;

	front = 0; rear = 0;

	printf("Function\n");
	printf("------------\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Print\n");
	printf("4. Exit\n");
	while (1)
	{
		printf("Select Number\n");
		scanf("%d", &selNum);

		switch (selNum)
		{
		case 1:
			{
				if (isFull())
				{
					printf("Error : Queue is Full\n");
					continue;
				}
				else
				{
					printf("Enter a key to be inserted in Queue\n");
					scanf("%d", &key);
					Insert(key);
				}

				break;
			}
		case 2:
			{
				if (isEmpty())
					printf("Error : Queue is empty\n");
				else
				{
					key = Delete();
					printf("Deleted Key : %d\n", key);
				}
				break;
			}
		case 3:
			{
				if (isEmpty())
					printf("Error : Queue is empty\n");
				else
					Print();

				break;
			}
		case 4:
			{
				return 0;
			}
		}
	}

	return 0;
}

/*
Description: Check if the circular queue is empty or not
Input: None
Output: if the queue is empty, return 1
		if the queue is not empty, return 0
*/
int isEmpty ()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

/*
Description: Check if the circular queue is full or not
Input: None
Output: if the queue is full, return 1
		if the queue is not full, return 0
*/
int isFull ()
{
	if (front == (rear + 1) % MAXSIZE)
		return 1;
	else
		return 0;
}

/*
Description: Insert the key received from main func into the queue
Input: (int)key value
Output: None
*/
void Insert (int key)
{
	queue[rear] = key;

	rear = (rear + 1) % MAXSIZE;
}

/*
Description: Delete a key from the queue
Input: None
Output: A key which front value indicates on the queue
*/
int Delete ()
{
	int tmp;
	
	tmp = queue[front];
	front = (front + 1) % MAXSIZE;

	return (tmp);
}

void Print ()
{
	int current = front;
	int end = (rear + 1) % MAXSIZE;

	current = (current + 1) % MAXSIZE;
	while (current != end)
	{
		printf("%d ", queue[current]);
		current = (current + 1) % MAXSIZE;
	} printf("\n");
}