#pragma
#include "libs.h"
using namespace std;

const int NUMBER_SIZE = 10;

class TrieNode
{
public:
	TrieNode* children[NUMBER_SIZE];
	bool isEndOfWord;
	TrieNode()
	{
		isEndOfWord = false;
		for (int i = 0; i < NUMBER_SIZE; i++)
		{
			children[i] = NULL;
		}
	}
};

class TrieTree
{
public:
	TrieTree()
	{
		root = new TrieNode();
	}
	void clear()
	{
		root = new TrieNode();
	}
	void insert(int s)
	{
		string key = to_string(s);
		TrieNode* pCrawl = root;
		for (int i = 0; i < key.length(); i++)
		{
			int index = key[i] - '0';
			if (!pCrawl->children[index])
				pCrawl->children[index] = new TrieNode();
			pCrawl = pCrawl->children[index];
		}
		pCrawl->isEndOfWord = true;
	}
	void insert(string key)
	{
		TrieNode* pCrawl = root;
		for (int i = 0; i < key.length(); i++)
		{
			int index = key[i] - '0';
			if (!pCrawl->children[index])
				pCrawl->children[index] = new TrieNode();
			pCrawl = pCrawl->children[index];
		}
		pCrawl->isEndOfWord = true;
	}
	bool search(int s)
	{
		string key = to_string(s);
		TrieNode* pCrawl = root;
		for (int i = 0; i < key.length(); i++)
		{
			int index = key[i] - '0';
			if (!pCrawl->children[index])
				return false;
			pCrawl = pCrawl->children[index];
		}
		return pCrawl->isEndOfWord;
	}
	bool search(string key)
	{
		TrieNode* pCrawl = root;
		for (int i = 0; i < key.length(); i++)
		{
			int index = key[i] - '0';
			if (!pCrawl->children[index])
				return false;
			pCrawl = pCrawl->children[index];
		}
		return pCrawl->isEndOfWord;
	}

private:
	TrieNode* root;
};