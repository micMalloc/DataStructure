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

int setMenuTable ();
int checkChild (nodePtr);
nodePtr Search (int, nodePtr);
void Insert (int, nodePtr*);
void Delete (int, nodePtr);
void exchangeNode (nodePtr, nodePtr);
nodePtr makeNode ();

void postorder (nodePtr);
void inorder (nodePtr);
void preorder (nodePtr);
void freeAllNodes (nodePtr*);

nodePtr parent;

int main (void)
{
	int menu, key;
	nodePtr root = NULL;
	nodePtr target = NULL;
	
	printf("=========================================\n");
	printf("  Implementation of Binary Search Tree  \n");
	printf("=========================================\n");
	while (1)
	{

		switch (setMenuTable())
		{
		case 1:
			{
				printf("Enter a key to be inserted\n");
				scanf("%d", &key);
				/*
				if (Search(key, root))
					printf("Already exist\n");
				else
					Insert(key, root);*/
				parent = NULL;
				Insert(key, &root);
				break;
			}
		case 2:
			{
				printf("Enter the key to be deleted\n");
				scanf("%d", &key);

				parent = NULL;
				target = Search(key, root);
				if (target)
					Delete(key, target);
				else
					printf("Not Found\n");
				break;
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
 
int setMenuTable ()
{
	int menu;

	printf("-------------------\n");
	printf(" Select the number\n");
	printf("-------------------\n");
	printf(" 1. Insert key\n");
	printf(" 2. Delete key\n");
	printf(" 3. Print Tree\n");
	printf(" 4.    Exit\n");
	printf("-------------------\n");

	scanf("%d", &menu);

	return menu;
}

int checkChild (nodePtr current)
{
	if (current->leftChild && current->rightChild)
		return 2;
	else if (current->leftChild || current->rightChild)
		return 1;
	else
		return 0;
}

/*
Description: Search and check if new key already exist or not
Input: Key value and Root node's address
Output: If There is no key that's same to new key, return NULL
		Elese, return the node's address that has same key
*/
nodePtr Search (int key, nodePtr current)
{
	if (current != NULL)
	{
		if (current->key == key)
			return current;
		else if (current->key > key)
		{
			parent = current;
			return (Search(key, current->leftChild));
		}
		else
		{
			parent = current;
			return (Search(key, current->rightChild));
		}
	} return current;
}

/*
Description: Find location that new node will be inserted and insert new node
Input: Key value and The Address of variable that has the address of root node
Output: None
*/
/*
void Insert (int key, nodePtr* current)
{
	if ((*current) == NULL){
		(*current) = makeNode(key);
	} else if ((*current)->key > key) {
		if ((*current)->leftChild)
			Insert(key, &(*current)->leftChild);
		else
			(*current)->leftChild = makeNode(key);
	} else {
		if ((*current)->rightChild)
			Insert(key, &(*current)->rightChild);
		else
			(*current)->rightChild = makeNode(key);
	}
}*/
void Insert (int key, nodePtr *root)
{
	if (*root)
	{
		if (Search(key, *root) != NULL)
			printf("Already exist\n");
		else
		{
			if (parent->key > key)
				parent->leftChild = makeNode(key);
			else
				parent->rightChild = makeNode(key);
		}
	}
	else
		*root = makeNode(key);
}

void Delete (int key, nodePtr current)
{
	nodePtr sub = NULL;

	if (checkChild(current) == 0)
	{ /* Leaf - Node Just Delete It */
		free(current);
		if (parent->key > key)
			parent->leftChild = NULL;
		else
			parent->rightChild = NULL;
	}
	else if (checkChild(current) == 1)
	{
		if (current->leftChild)
		{
			sub = current->leftChild;
			current->leftChild = sub->leftChild;
			current->rightChild = sub->rightChild;
			sub->leftChild = current;
			current = sub;

			Delete(key, current->leftChild);
		}
		else
		{
			sub = current->rightChild;
			current->leftChild = sub->leftChild;
			current->rightChild = sub->rightChild;
			sub->rightChild = current;
			current = sub;

			Delete(key, current->rightChild);
		}
	}
	else
	{

	}
}

void exchangeNode (nodePtr parentNode, nodePtr childNode)
{
	parentNode->leftChild = childNode->leftChild;
	parentNode->rightChild = childNode->rightChild;
	childNode->leftChild = parentNode;
	parentNode = childNode;
}

/*
Description: Create a node, initialize it and check if it is NULL or not, then return it
Input: key value
Output: New node's address
*/
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

/*
Description: Print all nodes in the tree by postorder
Input: Root node's address
Output: None
*/
void postorder (nodePtr current)
{
	if (current)
	{
		postorder(current->leftChild);
		postorder(current->rightChild);
		printf("%11d\n", current->key);
	}
}

/*
Description: Print all nodes in the tree by inorder way
Input: Root node's address
Output: None
*/
void inorder (nodePtr current)
{
	if (current)
	{
		inorder(current->leftChild);
		printf("%11d\n", current->key);
		inorder(current->rightChild);
	}
}

/*
Description: Print all nodes in the tree by preorder
Input: Root node's address
Output: None
*/
void preorder (nodePtr current)
{
	if (current)
	{
		printf("%11d\n", current->key);
		preorder(current->leftChild);
		preorder(current->rightChild);
	}
}

/*
Description: Free All nodes in the Tree by using postorder visiting way
Input: The Address of variable that has the address of root node
Output: None
*/
void freeAllNodes (nodePtr* current)
{
	if ((*current))
	{
		freeAllNodes(&(*current)->leftChild);
		freeAllNodes(&(*current)->rightChild);
		free((*current));
		(*current) = NULL;
	}
}