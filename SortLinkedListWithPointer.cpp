#include <iostream>
#include <assert.h>

struct Node {
	int data;
	Node *next;
};

void pushInback(Node **head_ref, const int data);
void printList(Node **head_ref);

//Node* sort_list(Node* head) {
//	Node *top = nullptr; // first Node we will return this value
//	Node *current = nullptr;
//	bool sorted = false;
//	while (sorted == false) {
//		// we are going to look for the lowest value in the list
//		Node *parent = head;
//		Node *lowparent = head; // we need this because list is only linked forward
//		Node *low = head; // this will end up with the lowest Node
//		sorted = true;
//		do {
//			// find the lowest valued key
//			Node* next = parent->next;
//			if (parent->data > next->data) {
//				lowparent = parent;
//				low = next;
//				sorted = false;
//			}
//			parent = parent->next;
//		} while (parent->next != nullptr);
//		if (current != nullptr) { // first time current == nullptr
//			current->next = low;
//		}
//		// remove the lowest item from the list and reconnect the list
//		// basically you are forming two lists, one with the sorted Nodes 
//		// and one with the remaining unsorted Nodes
//		current = low;
//		if (current == head) { head = current->next; }
//		lowparent->next = low->next;
//		current->next = nullptr;
//		if (top == nullptr) {
//			top = current;
//		}
//	};
//	current->next = head;
//	return top;
//}

void sortedInsert(struct Node**, struct Node*);

// function to sort a singly linked list using insertion sort 
void insertionSort(struct Node **head_ref)
{
	// Initialize sorted linked list 
	struct Node *sorted = NULL;

	// Traverse the given linked list and insert every 
	// node to sorted 
	struct Node *current = *head_ref;
	while (current != NULL)
	{
		// Store next for next iteration 
		struct Node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}

/* function to insert a new_node in a list. Note that this
function expects a pointer to head_ref as this can modify the
head of the input linked list (similar to push())*/
void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL &&
			current->next->data < new_node->data)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
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

int main()
{
	Node *head = nullptr;
	//
	pushInback(&head, 5);
	pushInback(&head, 2);
	pushInback(&head, 1);
	pushInback(&head, 3);
	pushInback(&head, 2);
	//
	printList(&head);
	//
	insertionSort(&head);
	//
	printList(&head);
	//
	system("pause");
}