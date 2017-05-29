#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int key;
	struct NODE* prev;
	struct NODE* next;
} node;
typedef node* nodePtr;

nodePtr makeNode ();
void insert_ (int, nodePtr, nodePtr*);
int delete_ (int, nodePtr);
void printHtoT (nodePtr);
void printTtoH (nodePtr);
void freeAllNodes (nodePtr);

int main (void)
{
	int menu, key;
	nodePtr head = makeNode(), tail = NULL;
	
	if (head == NULL)
	{
		printf("Error : Can't allocate memory\n");
		exit(1);
	}

	head->prev = head->next = NULL;
	tail = head;

		printf("==================================\n");
	printf("  Implementation of Linked List  \n");
	printf("==================================\n");
	while (1)
	{
		printf("-------------------\n");
		printf(" Select the number\n");
		printf("-------------------\n");
		printf(" 1. Insert key\n");
		printf(" 2. Delete key\n");
		printf(" 3. Print List\n");
		printf(" 4.    Exit\n");
		printf("-------------------\n");
		
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			{
				printf("Enter a key to be inserted\n");
				scanf("%d", &key);

				insert_(key, head, &tail);
				break;
			}
		case 2:
			{
				printf("Enter the key to be deleted\n");
				scanf("%d", &key);

				if (delete_(key, head))
					printf("SUCCESS\n");
				else
					printf("Not Found\n");
				break;
			}
		case 3:
			{
				printf(" 1. Print Front to Tail\n");
				printf(" 2. Print Tail to Front\n");
				scanf("%d", &menu);
				if (menu == 1)
				{
					printf("----------------------\n");
					printf("    Current Values\n");
					printf("----------------------\n");
					printHtoT(head->next);
				}
				else if (menu == 2)
				{
					printf("----------------------\n");
					printf("    Current Values\n");
					printf("----------------------\n");
					printTtoH(tail);
				}
				else
					printf("Error : Invalid Value");
				break;
			}
		case 4:
			{
				freeAllNodes(head);
				return 0;
			}
		default:
			printf("Error : Invalid Value");
		}
	}

	return 0;
}

/*
Description: Make a node and return the address of new node by using malloc function
Input: None
Output: None
*/
nodePtr makeNode ()
{
	return ((nodePtr)malloc(1 *sizeof(node)));
}

/*
Description: Make new node and store new key into that node then link it at the list
Input: key to be inserted and head address
Output: None
*/
void insert_ (int key, nodePtr current, nodePtr* tailAdr)
{
	nodePtr newNode = makeNode();

	/* Defensive Code */
	if (newNode == NULL)
	{
		printf("Error : Heap is full\n");
		exit(1);
	}
	newNode->key = key;

	/* Find Location that new node will be inserted */
	while(current->next)
		current = current->next;

	current->next = newNode;
	newNode->prev = current;
	newNode->next = NULL;

	(*tailAdr) = newNode;
}

/*
Description: Find the node which has the key to be deleted and free it
Input: key to be deleted and head address
Output: If deletion is success, return 1
		Else, return 0
*/
int delete_ (int key, nodePtr current)
{
	while(current)
	{
		if (current->key == key)
			break;
		current = current->next;
	}

	if (current)
	{
		current->prev->next = current->next;
		free(current);
		return 1;
	}
	else
		return 0;
}

/*
Description: Print all nodes that are in the List from Head to Tail
Input: The next node of head's address
Output: None
*/
void printHtoT (nodePtr front)
{
	while(front)
	{
		printf("%d ", front->key);
		front = front->next;
	} printf("\n");
}

/*
Description: Print all nodes that are in the List from Tail to Head
Input: The next node of head's address
Output: None
*/
void printTtoH (nodePtr tail)
{
	while(tail->prev)
	{
		printf("%d ", tail->key);
		tail = tail->prev;
	} printf("\n");
}

/*
Description: Free all nodes in the List
Input: None
Output: None
*/
void freeAllNodes (nodePtr current)
{
	nodePtr prev = NULL;

	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
}