#include <iostream>

struct Node {
	int data;
	Node *left, *right;
	Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

inline Node *insert(Node *root,const int data)
{
	if (root == nullptr)
		return new Node(data);
	else 
	{
		Node *curr;
		if (data <= root->data) {
			curr = insert(root->left, data);
			root->left = curr;
		}
		else {
			curr = insert(root->right, data);
			root->right = curr;
		}
		return root;
	}
}

void printLevelOrder(Node *root);
void printGivenLevel(Node *root, int level);
int height(Node *root);

void printLevelOrder(Node *root)
{
	int h = height(root) + 1;
	for (int i = 1; i <= h; ++i)
		printGivenLevel(root, i);
}

void printGivenLevel(Node *root, int level)
{
	if (root == nullptr) return;
	if (level == 1) std::cout << root->data << "\t";
	else if(level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

int height(Node *root) 
{
	if (root == nullptr)
		return -1;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if (rightHeight > leftHeight)
		return (rightHeight + 1);
	else
		return (leftHeight + 1);
}

int main() 
{
	Node *root = nullptr;
	//
	root = insert(root, 6);
	//
	root = insert(root, 4);
	root = insert(root, 8);
	//
	root = insert(root, 3);
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 9);
	//
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 9);
	root = insert(root, 10);

	//
	std::cout << "Height of the binary tree : " << height(root) << std::endl;
	printLevelOrder(root);
	std::cout << std::endl;
	//
	system("pause");
}