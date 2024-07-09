#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class TrieNode
{
public:
    char ch;
    bool IsTerminal;
    TrieNode *children[26];
    TrieNode(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->IsTerminal = 0;
    }
};

class Trie
{
private:
    void InsertUtil(TrieNode *&root, string word)
    {
        if (word.length() == 0)
        {
            root->IsTerminal = 1;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a';

        if (root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else
        {
            child = root->children[index];
        }

        InsertUtil(child, word.substr(1));
    }

    bool SearchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->IsTerminal;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            return 0;
        }
        else
        {
            child = root->children[index];
        }

        return SearchUtil(child, word.substr(1));
    }

    void deleteUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->IsTerminal = 0;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] == NULL)
        {
            return;
        }
        else
        {
            child = root->children[index];

            deleteUtil(child, word.substr(1));
        }
    }

public:
    TrieNode *root;

    Trie()
    {
        this->root = new TrieNode('a');
    }

    void insertWord(string word)
    {
        InsertUtil(root, word);
    }

    bool searchWord(string word)
    {
        return SearchUtil(root, word);
    }

    void deleteWord(string word)
    {
        deleteUtil(root, word);
    }
};
int main()
{
    Trie *t = new Trie();

    t->insertWord("kartik");
    t->insertWord("kaustubh");
    t->insertWord("radhika");
    t->insertWord("arya");
    cout << "Arya is " << t->searchWord("arya") << endl;
    t->deleteWord("arya");
    cout << "Arya is " << t->searchWord("arya") << endl;
    return 0;
}