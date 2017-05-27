#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BINARYNODE
{
	int key;
	struct BINARYNODE *leftChild;
	struct BINARYNODE *rightChild;
};
typedef struct BINARYNODE* binTreePtr;

struct GENERALINFO
{
	int tree_level;
	int key;
	char child_key[10];
	binTreePtr binNode;
	struct GENERALINFO *next;
};
typedef struct GENERALINFO* genInfoPtr;

void constructBinTree (binTreePtr*, genInfoPtr*, struct GENERALINFO);
void Search (genInfoPtr*, struct GENERALINFO);
void preorderPrint (binTreePtr);
void postorderFree (binTreePtr);
void listFree (genInfoPtr);
void linkNode (binTreePtr*, genInfoPtr*, struct GENERALINFO);

/*
Description : Receive file pointer by using fopen function.
			  main function call constructBinTree function, main function reading data from file.
			  and then, call preorderPrint, postorderFree and listFree functions.
input : none
output : 0
*/
int main ()
{
	binTreePtr root = NULL;
	genInfoPtr infoList = NULL;
	struct GENERALINFO new_info;

	FILE *fp;
	fp = fopen("tree3.txt", "r");
	if (fp == NULL)
	{
		printf("file load fail");
		exit(1);
	}

	while(fscanf(fp, "%d %d %s\n", &new_info.tree_level, &new_info.key, new_info.child_key) != EOF)
		constructBinTree(&root, &infoList, new_info);

	printf("=======================================\n");
	printf("Print RESULT OF CONVERTION by preorder\n");
	printf("=======================================\n");
	preorderPrint (root);

	postorderFree (root);
	listFree (infoList);

	fclose(fp);

	return 0;
}

/*
Description : Find NULL point that proper location of tree by calling itself recursively.
			  But if information list pointer is not NULL, change that pointer to last list by using while loop.
			  And then, call linkNode function. 
input : binary tree pointer's address, information list pointer's address and information node
output : 
*/
void constructBinTree (binTreePtr *parent, genInfoPtr *infoList, struct GENERALINFO info)
{
	genInfoPtr tmp_list;

	if ((*parent) == NULL)
	{	
		if ((*infoList) != NULL)
		{
			tmp_list = (*infoList);
			while (tmp_list->next)
				tmp_list = tmp_list->next;

			constructBinTree(&(*parent), &tmp_list->next, info);
		}
		else
			linkNode(&(*parent), &(*infoList), info);
	}
	else
		Search (&(*infoList), info);
}

/*
Description : Find location comparing with data in information list and new infomation.
			  if new information's key and child key in information list, call constructBinary function by passing address of leftchild.
			  if new information's tree level and tree level in information list, call constructBinary function by passing address of rightchild.
input : information list pointer's address and new information node
output : none
*/
void Search (genInfoPtr *infoList, struct GENERALINFO new_info)
{
	genInfoPtr tmp_list = *infoList;
	int child_key;

	while(tmp_list)
	{
		child_key = atoi(tmp_list->child_key);
		if (child_key == new_info.key)
		{
			constructBinTree(&tmp_list->binNode->leftChild, &tmp_list->next, new_info);
			break;
		}
		else if (tmp_list->tree_level == new_info.tree_level)
		{
			constructBinTree(&tmp_list->binNode->rightChild, &tmp_list->next, new_info);
			break;
		}
		tmp_list = tmp_list->next;
	}
}

/*
Description : Link new information node to information list.
			  Link new binary node to proper location of tree receieved from calling function.
input : binarytree pointer's address, information list pointer's address and new information node
output : none
*/
void linkNode (binTreePtr *child, genInfoPtr *list, struct GENERALINFO info)
{
	genInfoPtr new_info;
	binTreePtr new_node;

	new_info = (genInfoPtr)malloc(1 * sizeof(struct GENERALINFO));
	if (new_info == NULL)
	{
		printf("malloc fail\n");
		exit(1);
	}
	new_info->tree_level = info.tree_level;
	new_info->key = info.key;
	strcpy(new_info->child_key, info.child_key);

	new_node = (binTreePtr)malloc(1 * sizeof(struct BINARYNODE));
	if (new_node == NULL)
	{
		printf("malloc fail");
		exit(1);
	}

	new_info->next = NULL;
	new_info->binNode = new_node;
	(*list) = new_info;
			
	new_node->key = new_info->key;
	new_node->leftChild = new_node->rightChild = NULL;
	(*child) = new_node;
}

/*
Description : Print constructed binary tree by using preorder traversal.
input : binary tree root pointer
output : none
*/
void preorderPrint (binTreePtr root)
{
	if (root)
	{
		printf("%17d\n", root->key);
		preorderPrint(root->leftChild);
		preorderPrint(root->rightChild);
	}
}

/*
Description : Deallocated binary tree's memory by using postorder traversal and free function.
input : The root of binary tree received from main function
output : none
*/
void postorderFree (binTreePtr root)
{
	if (root)
	{
		postorderFree(root->leftChild);
		postorderFree(root->rightChild);
		free(root);
	}
}

/*
Description : Deallocated infoList's memory by using free function.
input : infoList's head pointer
output : none
*/
void listFree (genInfoPtr p)
{
	genInfoPtr prev = NULL;

	while (p)
	{
		prev = p;
		p = p->next;
		free(prev);
	}
}