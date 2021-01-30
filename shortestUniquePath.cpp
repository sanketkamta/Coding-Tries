#include <bits/stdc++.h>
using namespace std;
#define MAX 256
#define MAX_WORD_LEN 500

struct TrieNode
{
	struct TrieNode *child[MAX];
	int feq;
};

struct TrieNode *
newTrieNode(void)
{
	struct TrieNode *newNode = new TrieNode;
	newNode->feq = 1;
	for (int i = 0; i < MAX; i++)
		newNode->child[i] = NULL;
	return newNode;
}

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pNode = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i];
		if (!pNode->child[index])
			pNode->child[index] = newTrieNode();
		else
			(pNode->child[index]->feq)++;
		pNode = pNode->child[index];
	}
}

void findAllPrefixes(struct TrieNode *root, char prefix[], int ind)
{
	if (root == NULL)
		return;
	if (root->feq == 1)
	{
		prefix[ind] = '\0';
		cout << prefix << " ";
		return;
	}
	for (int i = 0; i < MAX; i++)
	{
		if (root->child[i] != NULL)
		{
			prefix[ind] = i;
			findAllPrefixes(root->child[i], prefix, ind + 1);
		}
	}
}

void findPrefixes(string arr[], int n)
{
	struct TrieNode *root = newTrieNode();
	root->feq = 0;
	for (int i = 0; i < n; i++)
		insert(root, arr[i]);
	char prefix[MAX_WORD_LEN];
	findAllPrefixes(root, prefix, 0);
}

int main()
{
	string arr[] = {"zebra", "dog", "duck", "dove"};
	int n = sizeof(arr) / sizeof(arr[0]);
	findPrefixes(arr, n);
	return 0;
}
