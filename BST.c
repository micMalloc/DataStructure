/* Implementation of Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int key;
	struct NODE* leftChild;
	struct NODE* rightChild;
} node;
typedef node* nodePtr;

nodePtr Search (int, nodePtr);
void Insert (int, nodePtr*);
//int Delete (int);
nodePtr makeNode ();

void postorder (nodePtr);
void inorder (nodePtr);
void preorder (nodePtr);
void freeAllNodes (nodePtr*);

int main (void)
{
	int menu, key;
	nodePtr root = NULL;

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

				if (Search(key, root))
					printf("Already exist\n");
				else
					Insert(key, &root);
				break;
			}
		case 2:
			{
				/*(printf("Enter the key to be deleted\n");
				scanf("%d", &key);

				if (Search(key, root)) {
					printf("SUCCESS\n");
				}
				else
					printf("Not Found\n");
				break;*/
			}
		case 3:
			{
				printf(" 1. Print All by Preorder\n");
				printf(" 2. Print All by Inorder\n");
				printf(" 3. Print All by Postorder\n");
				scanf("%d", &menu);
				if (menu == 1)
				{
					printf("----------------------\n");
					printf("    Print Preorder\n");
					printf("----------------------\n");
					preorder(root);
				}
				else if (menu == 2)
				{
					printf("----------------------\n");
					printf("    Print Inorder\n");
					printf("----------------------\n");
					inorder(root);
				}
				else if (menu == 3)
				{
					printf("----------------------\n");
					printf("    Print Postorder\n");
					printf("----------------------\n");
					inorder(root);
				}
				else
					printf("Error : Invalid Value");
				break;
			}
		case 4:
			{
				freeAllNodes(&root);
				return 0;
			}
		default:
			printf("Error : Invalid Value");
		}
	}

	return 0;
}

nodePtr Search (int key, nodePtr current)
{
	if (current != NULL)
	{
		if (current->key == key)
			return current;
		else if (current->key > key)
			return (Search(key, current->leftChild));
		else
			return (Search(key, current->rightChild));
	} return current;
}

void Insert (int key, nodePtr* current)
{
	if ((*current) == NULL)
		(*current) = makeNode(key);
	else if ((*current)->key > key)
	{
		if ((*current)->leftChild)
			Insert(key, &(*current)->leftChild);
		else
			(*current)->leftChild = makeNode(key);
	}
	else
	{
		if ((*current)->rightChild)
			Insert(key, &(*current)->rightChild);
		else
			(*current)->rightChild = makeNode(key);
	}
}

nodePtr makeNode (int key)
{
	nodePtr newNode = (nodePtr)malloc(1 * sizeof(node));

	if (newNode == NULL)
	{
		printf("Error : Can not allocate Memory\n");
		exit(1);
	}

	newNode->key = key;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return (newNode);
}

void postorder (nodePtr current)
{
	if (current)
	{
		postorder(current->leftChild);
		postorder(current->rightChild);
		printf("%11d\n", current->key);
	}
}

void inorder (nodePtr current)
{
	if (current)
	{
		inorder(current->leftChild);
		printf("%11d\n", current->key);
		inorder(current->rightChild);
	}
}

void preorder (nodePtr current)
{
	if (current)
	{
		printf("%11d\n", current->key);
		preorder(current->leftChild);
		preorder(current->rightChild);
	}
}

void freeAllNodes (nodePtr* current)
{
	if ((*current))
	{
		freeAllNodes(&(*current)->leftChild);
		freeAllNodes(&(*current)->rightChild);
		free((*current));
	}
}