#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    Trie trie;
    vector<string> words = {
        "राम",
        "रामायण",
        "रामकथा",
        "राज",
        "राजा",
        "राज्य",
        "रानी",
        "राष्ट्र"
    };

    for (const auto &word : words) {
        trie.insert(word);
    }
    cout << trie.search("राम") << endl;
    cout << trie.search("राज") << endl;
    cout << trie.search("राजकुमार") << endl;

    cout << "Standard Trie Node Count: "
         << trie.countNodes() << endl;

    return 0;
}
