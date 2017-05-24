#include <stdio.h>
#include <stdlib.h>

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
void printQ ();
void Free ();

nodePtr front, rear;

int main (void)
{
	int num, key;
	nodePtr newNode;
	
	front = isFull();
	if (front == NULL)
		exit(1);
	else
	{
		front->next = NULL;
		rear = front;
	}

	printf("Function\n");
	printf("------------\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Print\n");
	printf("4. Exit\n");
	while (1)
	{
		printf("Select Number\n");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			{
				printf("Enter a key to be inserted in Queue\n");
				scanf("%d", &key);

				newNode = isFull();
				if (newNode == NULL)
				{
					printf("Error : Queue is Full\n");
					exit(1);
				}
				else
					Insert(key, newNode);

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
					printQ();

				break;
			}
		case 4:
			{
				Free();
				return 0;
			}
		}
	}

	return 0;
}

int isEmpty ()
{
	if (front == rear)
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
	if (rear == front)
	{
		front->next = newNode;
		newNode->key = newKey;
		newNode->next = NULL;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		newNode->key = newKey;
		newNode->next = NULL;
		rear = newNode;
	}
}

int Delete ()
{
	int deletedKey;
	nodePtr tmp = front;
	
	front = front->next;
	deletedKey = front->key;

	free(tmp);

	return (deletedKey);
}

void printQ ()
{
	nodePtr tmp = front->next;

	printf("Current Queue\n");
	printf("--------------\n");
	while (tmp)
	{
		printf("%d ", tmp->key);
		tmp = tmp->next;
	} printf("\n");
}

void Free ()
{
	nodePtr prev = NULL;

	while (front)
	{
		prev = front;
		front = front->next;
		free(prev);
	}
}