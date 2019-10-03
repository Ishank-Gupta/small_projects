#include <iostream>
#include <map>

struct Node {
	int data;
	Node *next;
};

/***********************************************************************
* FUNCTION : insertNode

* DESCRIPTION : Add a new node and return the head of the Linked list.

* PARAMETER : Node *head, const int data

* RETURNVALUE : Node*
***********************************************************************/
Node* insertNode(Node *head, const int data)
{
		Node *next = new Node;
		next->data = data;
		next->next = nullptr;

		if (head == nullptr)
			head = next;
		else {
			Node *temp = head;
			while (temp->next != nullptr)
				temp = temp->next;
			temp->next = next;
		}
		return head;
}
/***********************************************************************
* FUNCTION : mergeLists

* DESCRIPTION : Merge and return the head of the two sorted Linked list.

* PARAMETER : Node* head1, Node* head2

* RETURNVALUE : Node*
***********************************************************************/
Node* mergeLists(Node* head1, Node* head2) {

	if (head1 == nullptr)
		return head2;
	else if (head2 == nullptr)
		return head1;
	else {
		Node *p = head1, *q = head2, *s = nullptr, *r = nullptr;
		if (p->data <= q->data)
		{
			s = p;
			p = p->next;
		}
		else
		{
			s = q;
			q = q->next;
		}
		r = s;

		while (p != nullptr || q != nullptr) {
			if (p == nullptr) {
				s->next = q;
				break;
			}
			if (q == nullptr) {
				s->next = p;
				break;
			}
			if (p->data <= q->data) {
				s->next = p;
				p = p->next;
			}
			else {
				s->next = q;
				q = q->next;
			}
			s = s->next;
		}
		return r;
	}
}
/***********************************************************************
	* FUNCTION : removeDuplicates

	* DESCRIPTION : Remove the duplicate value from the Linked list.

	* PARAMETER : Node* head

	* RETURNVALUE : Node*
***********************************************************************/
Node* removeDuplicates(Node* head) {

	if (head == nullptr)
		return head;
	else {
		Node *p = head, *q = head->next;
		while (q != nullptr) {
			if (p->data == q->data) {
				while (q != nullptr && p->data == q->data)
					q = q->next;
				p = p->next = q;
				if(p != nullptr)
					q = p->next;
			}
			else {
				p = q;
				q = q->next;
			}
		}
		return head;
	}
}
/***********************************************************************
* FUNCTION : deleteNode

* DESCRIPTION : Delete the node based on the position from the Linked list.

* PARAMETER : Node* head, int position

* RETURNVALUE : Node*
***********************************************************************/
Node* deleteNode(Node* head, int position) {

	if (head == nullptr)
		return head;
	else if (position == 0)
	{
		delete head;
		return nullptr;
	}
	else
	{
		Node *temp = head, *temp2 = nullptr;
		int pos = 0, limit = position - 1;
		//
		while (temp != nullptr && pos < limit) {
			temp = temp->next;
			++pos;
		}
		//
		//   if (temp->next == nullptr && limit > 0)
		//     return head;
		//   else if (limit < 0)
		//     return nullptr;

		if (temp == nullptr || temp->next == nullptr)
			return head;

		//if (temp->next->next != nullptr)
		temp2 = temp->next->next;

		delete temp->next;
		temp->next = temp2;
		return head;
	}
}

bool has_cycle(Node* head) {

	if (head == nullptr || head->next == nullptr)
		return false;

	std::multimap<int, Node *>  node_ptr;
	Node *temp = head;
	bool b_has_cycle = false;
	while (temp != nullptr) {
		auto itr = node_ptr.find(temp->data);
		if (itr != node_ptr.end()) {
			while (itr != node_ptr.end() && itr.first == temp->data) {
				if (itr.second == temp) {
					b_has_cycle = true;
					break;
				}
				++itr;
			}
		}
		node_ptr.insert(
			std::pair<int, Node *>(temp->data, temp));
		temp = temp->next;
	}
}

int main()
{
	Node *head1 = new Node, *head2 = new Node, *head = nullptr;
	head1 = head2 = nullptr;

	for (int i = 1; i < 6; ++i)
		head1 = insertNode(head1, i);

	for (int i = 5; i < 8; ++i)
		head2 = insertNode(head2, i);

	//head = mergeLists(head1, head2);
	int arr[6] = { 3,3,3,4,5,5 };
	for (int i = 0; i < 6; ++i)
		head = insertNode(head, arr[i]);

	head = removeDuplicates(head);

	system("pause");
}