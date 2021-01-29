#include <iostream>
using namespace std;

const int ALPHA = 26;

struct TrieNode
{
	struct TrieNode *children[ALPHA];
	bool isEndOfWord;
};

struct TrieNode *
getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHA; i++)
	{
		pNode->children[i] = NULL;
	}
	return pNode;
}

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return true;
}

int main()
{
	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	int n = sizeof(keys) / sizeof(keys[0]);
	struct TrieNode *root = getNode();

	for (int i = 0; i < n; i++)
	{
		insert(root, keys[i]);
	}
	search(root, "the") ? cout << "Yes \n" : cout << "No \n";
	search(root, "these") ? cout << "Yes \n" : cout << "No \n";
	return 0;
}
