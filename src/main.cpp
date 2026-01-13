#include <bits/stdc++.h>
using namespace std;

#include "trie.h"
#include "patricia_trie.h"

int main() {
    Trie trie;
    PatriciaTrie patricia;

    ifstream file("../data/hindi_words.txt");

    if (!file.is_open()) {
        cout << "Failed to open hindi_words.txt" << endl;
        return 0;
    }

    string word;
    int count = 0;

    while (file >> word) {
        trie.insert(word);
        patricia.insert(word);
        count++;
    }

    cout << "Total words inserted: " << count << endl;
    cout << "Standard Trie Nodes: " << trie.countNodes() << endl;
    cout << "Patricia Trie Nodes: " << patricia.countNodes() << endl;

    return 0;
}
