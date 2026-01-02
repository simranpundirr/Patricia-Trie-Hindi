#include "trie.h"
#include <iostream>

TrieNode::TrieNode() {
    isEnd = false;
}

Trie::Trie() {
    root = new TrieNode();
}

int Trie::countNodesHelper(TrieNode* node) {
    if (!node) return 0;

    int count = 1;
    for (auto &child : node->children) {
        count += countNodesHelper(child.second);
    }
    return count;
}

void Trie::insert(const std::string &word) {
    TrieNode* current = root;

    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->isEnd = true;
}

bool Trie::search(const std::string &word) {
    TrieNode* current = root;

    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children[ch];
    }
    return current->isEnd;
}

int Trie::countNodes() {
    return countNodesHelper(root);
}
