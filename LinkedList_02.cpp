#include <iostream>
#include <assert.h>

struct Node {
	int data;
	Node *next;
};

void pushInFront(Node **head_ref, const int data);
void pushInback(Node **head_ref, const int data);
void popFromFront(Node **head_ref);
void popFromBack(Node **head_ref);
void printList(Node **head_ref);
void moveFrontNode(Node **destHeadRef, Node **sourceHeadRef);
void moveLastNode(Node **destHeadRef, Node **sourceHeadRef);

void pushInFront(Node **head_ref, const int data)
{
	Node *node = new Node;
	node->data = data;
	if (*head_ref == nullptr)
	{
		node->next = nullptr;
		*head_ref = node;
		return;
	}
	else
	{
		node->next = *head_ref;
		*head_ref = node;
		return;
	}
}

void pushInback(Node **head_ref, const int data)
{
	Node *node = new Node;
	node->data = data;
	node->next = nullptr;
	if (*head_ref == nullptr)
	{
		*head_ref = node;
		return;
	}
	else
	{
		Node *temp = *head_ref;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = node;
	}

}

void popFromFront(Node **head_ref)
{
	if (*head_ref == nullptr)
	{
		std::cout << "The list is empty.\n";
		return;
	}
	else
	{
		Node *temp = *head_ref;
		*head_ref = (*head_ref)->next;
		delete temp;
	}
}

void popFromBack(Node **head_ref)
{
	if (*head_ref == nullptr)
	{
		std::cout << "The list is empty.\n";
		return;
	}
	else
	{
		Node *temp = *head_ref, *prev = *head_ref;
		while (temp->next != nullptr)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = nullptr;
		delete temp;
	}
}

void printList(Node **head_ref)
{
	if (*head_ref == nullptr)
	{
		std::cout << "The list is empty.\n";
		return;
	}
	else
	{
		int count = 1;
		Node *temp = *head_ref;
		std::cout << "\nThe elements in the list are : \n";
		while (temp != nullptr)
		{
			std::cout << count << ".	" << temp->data << ".\n";
			++count;
			temp = temp->next;
		}
	}
}

void moveFrontNode(Node **destHeadRef, Node **sourceHeadRef)
{
	if (*sourceHeadRef == nullptr)
	{
		std::cout << "The source Head node is empty.\n";
		return;
	}
	else
	{
		Node *temp = *sourceHeadRef;

		*sourceHeadRef = (*sourceHeadRef)->next;
		temp->next = *destHeadRef;
		*destHeadRef = temp;
		return;
	}
}

void moveLastNode(Node **destHeadRef, Node **sourceHeadRef)
{
	if (*sourceHeadRef == nullptr)
	{
		std::cout << "The source list is empty.\n";
		return;
	}
	else
	{
		Node *temp = *sourceHeadRef, *prev = nullptr;
		while (temp->next != nullptr)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = nullptr;
		temp->next = *destHeadRef;
		*destHeadRef = temp;
	}
}

int main()
{
	Node *headSource = nullptr, *headDest = nullptr;

	for (int i = 10; i < 101; i += 10)
		pushInback(&headSource, i);
	std::cout << "\nThe elements in the source list are : \n";
	printList(&headSource);

	for (int i = 110; i < 201; i += 10)
		pushInback(&headDest, i);
	std::cout << "\nThe elements in the destination list are : \n";
	printList(&headDest);

	moveLastNode(&headDest, &headSource);

	printList(&headSource);
	printList(&headDest);

	system("pause");
}