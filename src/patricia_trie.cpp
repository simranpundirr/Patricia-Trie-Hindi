#include "patricia_trie.h"

PatriciaTrie::PatriciaTrie() {
    root = new PatriciaNode("");
}

void PatriciaTrie::insert(string word) {
    insertHelper(root, word);
}

void PatriciaTrie::insertHelper(PatriciaNode* node, string word) {

    char c = word[0];
    if (node->children.find(c) == node->children.end()) {
        PatriciaNode* newNode = new PatriciaNode(word);
        newNode->isEnd = true;
        node->children[c] = newNode;
        return;
    }

    PatriciaNode* child = node->children[c];
    string label = child->label;
    int i = 0;
    while (i < label.size() && i < word.size() && label[i] == word[i]) {
        i++;
    }

    if (i == label.size() && i == word.size()) {
        child->isEnd = true;
        return;
    }

    if (i == label.size()) {
        insertHelper(child, word.substr(i));
        return;
    }
    if (i == word.size()) {
        PatriciaNode* newNode = new PatriciaNode(word);
        newNode->isEnd = true;

        child->label = label.substr(i);
        newNode->children[child->label[0]] = child;

        node->children[c] = newNode;
        return;
    }
    string common = word.substr(0, i);
    string oldSuffix = label.substr(i);
    string newSuffix = word.substr(i);

    PatriciaNode* splitNode = new PatriciaNode(common);
    node->children[c] = splitNode;

    child->label = oldSuffix;
    splitNode->children[oldSuffix[0]] = child;

    PatriciaNode* newNode = new PatriciaNode(newSuffix);
    newNode->isEnd = true;
    splitNode->children[newSuffix[0]] = newNode;
}

bool PatriciaTrie::search(string word) {
    return searchHelper(root, word);
}

bool PatriciaTrie::searchHelper(PatriciaNode* node, string word) {

    if (word.empty()) return node->isEnd;

    char c = word[0];
    if (node->children.find(c) == node->children.end()) return false;

    PatriciaNode* child = node->children[c];
    string label = child->label;

    if (word.substr(0, label.size()) != label) return false;

    return searchHelper(child, word.substr(label.size()));
}

int PatriciaTrie::countNodes() {
    return countNodesHelper(root);
}

int PatriciaTrie::countNodesHelper(PatriciaNode* node) {
    if (!node) return 0;

    int count = 1;
    for (auto& p : node->children) {
        count += countNodesHelper(p.second);
    }
    return count;
}
