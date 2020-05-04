#include <iostream>
#include<stdlib.h>

using namespace std;

class binTree
{
	int data;
	binTree *left, * right;

public:
	binTree();											//Constructor
	binTree(int);										//Parametirize Const

	binTree* insert(binTree*, int);						//Insert Function

	void inorder(binTree*);
};

binTree::binTree() :data(0), left(NULL), right(NULL)	//Default Const.
{

}
binTree::binTree(int value)								//Parametirize Const
{
	data = value;
	left = right = NULL;
}

binTree* binTree::insert(binTree* root, int value)
{
	if (!root)											//Inserrting 1st node, if NULL
	{
		return new binTree(value);
	}

	if (value > root->data)								//Insert data
	{
		root->right = insert(root->right, value);		//Insert Right
	}
	else
	{
		root->left = insert(root->left, value);			//Insert LEft
	}
		
	return root;
}

void binTree::inorder(binTree* root)
{
	if (!root)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

int main()
{
														//Creating Binary Tree
	binTree b, * root = NULL;
	root = b.insert(root, 50);
	b.insert(root, 40);
	b.insert(root, 30);
	b.insert(root, 20);
	b.insert(root, 10);

	b.inorder(root);

	system("PAUSE");
	return 0;
}