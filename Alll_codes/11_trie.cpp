// Trie / Prefix Tree : It is essential for Auto-Complete, Spell Checkers, and solving "Word Search II". 
// Key Idea: Store characters in nodes rather than full strings.

// trie.cpp
#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26]; // Array for 'a' to 'z'
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a'; // Map 'a'->0, 'b'->1
            if (curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    // Returns true if the word is in the trie
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == NULL) return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    // Returns true if there is any word starting with prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == NULL) return false;
            curr = curr->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search 'apple': " << trie.search("apple") << endl;   // 1 (True)
    cout << "Search 'app': " << trie.search("app") << endl;       // 0 (False)
    cout << "StartsWith 'app': " << trie.startsWith("app") << endl; // 1 (True)
    return 0;
}