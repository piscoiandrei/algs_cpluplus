#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};
Node* searchBFT(Node* root, int KEY)   // BREADTH FIRST TRAVERSAL
{
	if (root == NULL)
		return root;

	queue<Node*> q;
	Node* ans = NULL;
	q.push(root);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp->key == KEY) ans = temp;

		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
	return ans;
}

// DEPTH FIRST TRAVERSAL TYPES
                        // Preorder ROOT - LEFT - RIGHT (preordine)
                        // Inorder LEFT - ROOT - RIGHT (inordine)
                        // Postorder LEFT - RIGHT - ROOT (postordine)
void preoder(Node* root)
{
    if(root != NULL)
    {
        execOperations(root);
        preoder(root->left);
        postorder(root->right);
    }
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        execOperations(root);
        inorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        execOperations(root);
    }
}

