#include <iostream>
#include <map>
#include <set>

struct Node {
	Node(int data) : data(data), next(nullptr) {}
	int data;
	Node *next;
};

Node *last = nullptr;

Node* insertNode(Node *head, int data) 
{
	Node *node = new Node(data);
	if (head == nullptr)
		return node;
	Node *temp = head;
	while (temp->next != nullptr)
		temp = temp->next;
	last = temp;
	temp->next = node;
	return head;
}

bool has_cycle(Node* head) {

	if (head == nullptr || head->next == nullptr)
		return false;

	std::multimap<int, Node *>  node_ptr;
	Node *temp = head;
	bool b_has_cycle = false;
	while (temp != nullptr && b_has_cycle == false) {
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
	return b_has_cycle;

}

std::set<int> i_set;
std::pair<std::set<int>::iterator, bool> m_pair;

int main()
{
	/*bool isCycle = false;
	Node *head = nullptr, *temp = nullptr;
	for (int i = 1; i < 6; ++i)
		head = insertNode(head, i);

	temp = head->next->next;
	last->next = temp;

	isCycle = has_cycle(head);

	std::cout << std::boolalpha << isCycle << std::endl;*/

	m_pair = i_set.insert(10);
	if (m_pair.second == false)
		std::cout << std::boolalpha << m_pair.second << std::endl;

	system("pause");
}