#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

    int countNodesHelper(TrieNode* node) {
        if (!node) return 0;

        int count = 1;
        for (auto &child : node->children) {
            count += countNodesHelper(child.second);
        }
        return count;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) {
        TrieNode* current = root;

        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEnd = true;
    }

    bool search(const string &word) {
        TrieNode* current = root;

        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEnd;
    }

    int countNodes() {
        return countNodesHelper(root);
    }
};
