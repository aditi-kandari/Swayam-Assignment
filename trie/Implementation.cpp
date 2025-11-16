// Problem Statement:
// ------------------
// Implement a Trie (Prefix Tree) with the following operations:

// 1. insert(string word)
//    → Inserts a word into the Trie.

// 2. search(string word)
//    → Returns true if the word exists in the Trie.

// 3. startsWith(string prefix)
//    → Returns true if there is any word in the Trie that starts with the given prefix.

// Trie is a tree-like data structure used for efficient retrieval of strings, 
// especially useful for prefix-based searching (like autocomplete systems).


#include <string>
using namespace std;

// Trie Node structure
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // Search a full word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    // Check if there exists any word starting with a given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }
};
