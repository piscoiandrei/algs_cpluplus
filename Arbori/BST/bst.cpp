#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

ifstream in("source.in");
ofstream out("source.out");

struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* insertNode(Node* root, int x)
{
	if (root == NULL)
	{
		root = new Node;
		root->key = x;
		root->left = root->right = NULL;
		return root;
	}

	if (x > root->key)
		root->right = insertNode(root->right, x);
	if (x < root->key)
		root->left = insertNode(root->left, x);

	return root;
}

Node* searchNode(Node* root, int KEY)
{
	while (root != NULL)
	{
		if (root->key == KEY)
			return root;

		if (KEY > root->key)
			root = root->right;
		else
			root = root->left;
	}
	return NULL;
}

Node* findMin(Node* root)
{
	Node* minimum = new Node;
	minimum->key = INT_MAX;
	while (root != NULL)
	{
		if (root->key < minimum->key)
			minimum = root;

		if (root->left != NULL)
			root = root->left;
		else
			root = root->right;
	}
	return minimum;
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
			{
				root->right = deleteNode(root->right, KEY);
			}
			else
			{
				//frunza
				if (root->left == NULL && root->right == NULL)
				{
					delete root;
					root = NULL;
				}
				else
				{
					//un descendent
					if (root->right == NULL)
					{
						Node* temp = root;
						root = root->left;
						delete temp;
					}
					else
					{   //un descendent
						if (root->left == NULL)
						{
							Node* temp = root;
							root = root->right;
							delete temp;
						}
						// doi descendenti
						else
						{

							//gasim nodul minim in subarborele drept, deoarece el
							//nu va aveam mai mult de un subarbore
							Node* temp = findMin(root->right);
							out << temp->key << '\n';
							root->key = temp->key;
							root->right = deleteNode(root->right, temp->key); // stergem minimul

						}
					}
				}

			}
		}
	}
	return root;
}

void BFT(Node* root)
{
	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp != NULL) out << temp->key << ' ';

		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
}

void preordine(Node* root)
{
	if (root != NULL)
	{
		out << root->key << ' ';
		preordine(root->left);
		preordine(root->right);
	}
}
void inordine(Node* root)
{
	if (root != NULL)
	{
		inordine(root->left);
		out << root->key << ' ';
		inordine(root->right);
	}
}
void postordine(Node* root)
{
	if (root != NULL)
	{
		postordine(root->left);
		postordine(root->right);
		out << root->key << ' ';
	}
}

int main()
{
	Node* r = new Node;
	r->key = 20;
	r->left = NULL;
	r->right = NULL;

	insertNode(r, 13);
	insertNode(r, 24);

	for (int i = 2; i <= 6; i++)
		insertNode(r, i * i);

	///BFT(r);
	inordine(r);
}


