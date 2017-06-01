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