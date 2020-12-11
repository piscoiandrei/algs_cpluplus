#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
using namespace std;

ifstream in("source.in");
ofstream out("source.out");

struct Node {
	int key;
	Node* right;
	Node* left;
};

int height(Node* root)
{
	if (root == NULL)  // arborele e vid
		return -1;

	return 1 + max(height(root->right),height(root->left));

	/*int h_left = height(root->left);  // LONG VERSION
	int h_right = height(root->right);
	return 1 + max(h_left, h_right);*/
}

int balanceFactor(Node* root)
{
	return height(root->left) - height(root->left);

	/*int left = height(root->left);
	int right = height(root->left);
	return left - right;*/
}

Node* left_left(Node* nd)
{
	Node* t = nd->left;
	nd->left = t->right;
	t->right = nd;

	return t;
}

Node* right_right(Node* nd)
{
	Node* t = nd->right;
	nd->right = t->left;
	t->left = nd;

	return t;
}

Node* left_right(Node* nd)
{
	Node* t = nd->left;
	nd->left = right_right(t);

	return left_left(nd);
}

Node* right_left(Node* nd)
{
	Node* t = nd->right;
	nd->right = left_left(t);

	return right_right(nd);
}

Node* balance(Node* nd)
{
	int bf = balanceFactor(nd);

	if (bf > 1)
	{
		if (balanceFactor(nd->left) > 0)
			nd = left_left(nd);
		else
			nd = left_right(nd);
	}
	else
		if (bf < -1)
		{
			if (balanceFactor(nd->right) < 0)
				nd = right_right(nd);
			else
				nd = right_left(nd);
		}
	return nd;
}

Node* insertNode(Node* root, int x)
{
	if (root == NULL)
	{
		root = new Node;
		root->key = x;
		root->left = root->right = NULL;

		return root;
	}
	else
	{
		if (x > root->key)
		{
			root->right = insertNode(root->right, x);
			root = balance(root);
		}
		else
			if(x < root->key)
			{
				root->left = insertNode(root->left, x);
				root = balance(root);
			}
	}
	return root;
}

Node* searchNode(Node* root, int KEY)
{

	while (KEY != root->key)
	{
		if (KEY > root->key)
		{
			root = root->right;
		}
		else
			if (KEY < root->key)
			{
				root = root->left;
			}
		if (KEY == root->key)
			return root;
	}

	return NULL;
}

Node* findParent(Node* root, Node* nd)
{
	while (root != nd)
	{
		if (root->key > nd->key)
		{
			if (root->left == nd)
				return root;
			else
				root = nd->left;
		}
		else if (root->key < nd->key)
		{
			if (root->right == nd)
				return root;
			else
				root = nd->right;
		}

	}
	return NULL;
}

Node* findMin(Node* root)
{
	Node* minimumNode = new Node;
	int minimum = INT_MAX;

	if (root->key < minimum && root!=NULL)
	{
		minimum = root->key;
		minimumNode = root;
	}

	while (root != NULL)
	{
		if (root->left != NULL)
		{
			if (root->left->key < minimum)
			{
				minimum = root->left->key;
				minimumNode = root->left;
			}
			root = root->left;
		}
		else
			root = root->right;
	}

	return minimumNode;
}

Node* deleteNode(Node* root, int KEY)
{
	if (root == NULL)
		return root;
	else
	{
		if (KEY < root->key)
		{
			root->left = deleteNode(root->left, KEY);
		}
		else
		{
			if (KEY > root->key)
				root->right = deleteNode(root->right, KEY);
			else
			{
				// frunza
				if (root->left == NULL && root->right == NULL)
				{
					delete root;
					root = NULL;
				}
				else
				{
					// un descendent
					if (root->left == NULL)
					{
						Node* temp = root;
						root = root->right;
						delete temp;
					}
					else
					{
						if (root->right == NULL)
						{
							Node* temp = root;
							root = root->left;
							delete temp;
						}
						else // 2 descendenti
						{
							//gasim nodul minim in subarborele drept, deoarece el nu va aveam mai mult decat un subarbore
							Node* temp = findMin(root->right); // => trecem pe cazul cu un descendent
							root->key = temp->key;
							root->right = deleteNode(root->right, temp->key);
							// echivalent se poate face cu maxim in subarborele stang
						}
					}
				}
			}
		}
	}
	return root;
	//return balance(root);
   // AFTER MULTIPLE DELETION, REBALANCING MAY BE REQUIRED
}


int main()
{

}


