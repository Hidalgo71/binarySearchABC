#include <iostream>

using namespace std;

template <class T>
class BinaryTree
{

	struct node								//struct build for tree
	{
		T value;
		struct node* right;
		struct node* left;
	};

public:
	BinaryTree();
	void insert(T value);						//adding values
	void printInOrder();					//inorder traversal
private:
	struct node* root;

	void insert(struct node** node, T value);
	void printInOrder(struct node* node);

};

template <class T>
BinaryTree<T>::BinaryTree() 
{
	this->root = NULL;
}

template <class T>
void BinaryTree<T>::insert(T value)
{
	insert(&(this->root), value);
}

template <class T>
void BinaryTree<T>::insert(struct node** node, T value)
{
	if (*node == NULL) 
	{
		struct node* tmp = new struct node;
		tmp->value = value;
		tmp->left = NULL;
		tmp->right = NULL;
		*node = tmp;
	}
	else 
	{
		if (value > (*node)->value)			
		{
			insert(&(*node)->right, value);				//adding right
		}
		else 
		{
			insert(&(*node)->left, value);				//adding left
		}
	}
}

template <class T>
void BinaryTree<T>::printInOrder() 
{
	printInOrder(this->root);
	cout << std::endl;
}

template <class T>
void BinaryTree<T>::printInOrder(struct node* node) 
{
	if (node != NULL) 
	{
		printInOrder(node->left);
		cout << node->value << ", ";
		printInOrder(node->right);
	}
}


int main() 
{

	BinaryTree<char> charT;

	charT.insert('A');
	charT.insert('B');
	charT.insert('C');
	charT.insert('D');
	charT.insert('E');

	charT.printInOrder();

	system("PAUSE");
	return 0;
}