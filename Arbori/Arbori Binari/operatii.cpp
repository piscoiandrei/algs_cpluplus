#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
using namespace std;

// AFLAREA RADACINII, ARBORE REPREZENTAT CU VECTORI st[] si dr[];

int radacina(int st[], int dr[], int n)
{
	vector<int> TT(n+1, 0);// vectori de tati,radacina = i, unde TT[i] = 0
	TT[0] = -1;            // vectorul poate fi declarat si BOOL
	                       // deoarce dorim sa aflam nodul fara parinte

	for (int i = 1; i <= n; i++)
	{
		if (st[i])
			TT[st[i]] = i;
		if (dr[i])
			TT[dr[i]] = i;
	}

	for (int i = 1; i <= n; i++)
		if (!TT[i])
			return i;

	return 0;
}



struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* createNode(int KEY)
{
	auto node = new Node;
	node->key = KEY;
	node->left = node->right = NULL;

	return node;
}


//insertion by finding the first vacant node(left->right) in a BFT manner
void insertNode(Node **root, int KEY) // function call insertNode(&root,key)
{
	if (*root == NULL)
	{
		(*root) = createNode(KEY);
		return;
	}

	Node* nodeToInsert = createNode(KEY);
	queue<Node*> q;
	q.push(*root);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp->left == NULL)
		{
			temp->left = nodeToInsert;
			return;
		}
		else
			q.push(temp->left);

		if (temp->right == NULL)
		{
			temp->right = nodeToInsert;
			return;
		}
		else
			q.push(temp->right);
	}
}


int inaltimeArbore(Node* r)
{
    if(r==NULL) return -1;
    int hs = inaltimeArbore(r->left);
    int hd = inaltimeArbore(r->right);

    return 1+(hs>hd?hs:hd);
}
