#ifndef PATRICIA_TRIE_H
#define PATRICIA_TRIE_H

#include <bits/stdc++.h>
using namespace std;

struct PatriciaNode {
    string label;
    unordered_map<char, PatriciaNode*> children;
    bool isEnd;

    PatriciaNode(string s = "") {
        label = s;
        isEnd = false;
    }
};

class PatriciaTrie {
private:
    PatriciaNode* root;

    void insertHelper(PatriciaNode* node, string word);
    bool searchHelper(PatriciaNode* node, string word);
    int countNodesHelper(PatriciaNode* node);

public:
    PatriciaTrie();

    void insert(string word);
    bool search(string word);
    int countNodes();
};

#endif
