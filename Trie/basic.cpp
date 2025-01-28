#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    vector<TrieNode *> children;
    bool isTermnial;
    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            this->children.push_back(NULL);
        }
        this->isTermnial = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // BASE Case

        if (word.length() == 0)
        {
            root->isTermnial = 1;
            return;
        }

        // getting index of word
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        { // if presenet move forward
            child = root->children[index];
        }
        else
        { // if absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            return root->isTermnial;
        }
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            return 0;
        }
        else
        {
            child = root->children[index];
        }
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *tr;

    tr->insertword("kartik");

    cout << tr->search("kartik") << endl;
    return 0;
}