#include <bits/stdc++.h>
using namespace std;
const int ALPHA = 26;

struct TrieNode
{
	struct TrieNode *child[ALPHA];
	int isEndOfWord;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode();
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHA; i++)
	{
		pNode->child[i] = NULL;
	}
	return pNode;
}

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->child[index])
			pCrawl->child[index] = getNode();
		pCrawl = pCrawl->child[index];
	}
	pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string str)
{
	struct TrieNode *pCrawl = root;
	for (int i = 0; i < str.length(); i++)
	{
		int index = str[i] - 'a';
		if (!pCrawl->child[index])
			return false;
		pCrawl = pCrawl->child[index];
	}
	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

bool wordbreak(string str, struct TrieNode *root)
{
	int len = str.size();
	if (len == 0)
		return true;
	for (int i = 1; i <= len; i++)
	{
		if (search(root, str.substr(0, i)) && wordbreak(str.substr(i, len - i), root))
			return true;
	}
	return false;
}

int main()
{
	string dictionary[] = {"mobile", "samsung", "sam", "sung", "ma\n", "mango", "icecream", "and", "go", "i", "like", "ice", "cream"};
	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	struct TrieNode *root = getNode();
	for (int i = 0; i < n; i++)
		insert(root, dictionary[i]);
	wordbreak("ilikesamsung", root) ? cout << "Yes\n" : cout << " No\n";
}
