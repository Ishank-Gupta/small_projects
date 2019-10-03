#include <iostream>

struct StackNode {
	int data;
	StackNode *next;
};

bool isEmpty(StackNode *root);
void push(StackNode **root, const int data);
void pop(StackNode **root);
int peek(StackNode **root);
void printList(StackNode **root);

bool isEmpty(StackNode *root)
{
	/*if (root == nullptr)		return true;
	else						return false;*/

	return !root;
}

void push(StackNode **root, const int data)
{
	StackNode *node = new StackNode;
	node->data = data;
	if (*root == nullptr)
		node->next = nullptr;
	else
		node->next = *root;
	*root = node;
}

void pop(StackNode **root)
{
	if (isEmpty(*root))
	{
		std::cout << "The stack is underflow.\n";
		return;
	}
	else
	{
		StackNode *temp = new StackNode;
		temp = *root;
		*root = (*root)->next;
		delete temp;
		return;
	}
}

int peek(StackNode ** root)
{
	if (isEmpty(*root))
	{
		std::cout << "The stack is underflow.\n";
		return 0;
	}
	else
		return (*root)->data;
}

void printList(StackNode ** root)
{
	if (isEmpty(*root))
	{
		std::cout << "The stack is underflow.\n";
		return;
	}
	else
	{
		int num = 1;
		while (*root != nullptr)
		{
			std::cout << num << ".		" << (*root)->data << std::endl;
			++num;
			*root = (*root)->next;
		}
	}
}

int main()
{
	StackNode *head = nullptr;

	for (int i = 1; i < 101; ++i)
		push(&head, i);

	printList(&head);

	system("pause");
}