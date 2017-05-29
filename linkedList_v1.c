#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int key;
	struct NODE* next;
} node;
typedef node* nodePtr;

void insert_ (int, nodePtr);
int delete_ (int, nodePtr);
nodePtr makeNode ();
void printList (nodePtr);
void freeAllNodes (nodePtr);

int main (void)
{
	int key, menu;
	nodePtr head = makeNode();

	/* Defensive Code */
	if (head == NULL)
	{
		printf("Error : Heap is full\n");
		exit(1);
	} head->next = NULL;

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

				insert_(key, head);
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
				printf("----------------------\n");
				printf("    Current Values\n");
				printf("----------------------\n");
				printList(head->next);
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
Description: Make new node and store new key into that node then link it at the list
Input: key to be inserted and head address
Output: None
*/
void insert_ (int key, nodePtr current)
{
	nodePtr newNode = makeNode();

	/* Defensive Code */
	if (newNode == NULL)
	{
		printf("Error : Heap is full\n");
		exit(1);
	}
	newNode->key = key;
	newNode->next = NULL;

	/* Find Location that new node will be inserted */
	while(current->next)
		current = current->next;
	current->next = newNode;
}

/*
Description: Find the node which has the key to be deleted and free it
Input: key to be deleted and head address
Output: If deletion is success, return 1
		Else, return 0
*/
int delete_ (int key, nodePtr current)
{
	nodePtr prev = NULL;

	/* Find the Node to be deleted from Linked-List */
	do {
		if (current->key == key)
			break;
		prev = current;
		current = current->next;
	} while (current);

	if (current)
	{
		prev->next = current->next;
		free(current);
		return 1;
	}	
	else
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
Description: Print all nodes that are in the List
Input: The next node of head's address
Output: None
*/
void printList (nodePtr current)
{
	while(current)
	{
		printf("%d ", current->key);
		current = current->next;
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