#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;
    int countNodesHelper(TrieNode* node);

public:
    Trie();
    void insert(const std::string &word);
    bool search(const std::string &word);
    int countNodes();
};

#endif
