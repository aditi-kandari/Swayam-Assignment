// Problem Statement:
// ------------------
// Extend the Trie data structure to support the following operations:
// 1. insert(string word)   → Insert a word into the Trie.
// 2. search(string word)   → Check if a word exists in the Trie.
// 3. startsWith(string prefix) → Check if any word starts with the given prefix.
// 4. deleteWord(string word)  → Delete a word from the Trie.

// Note:
// Deletion should only remove nodes that are not shared by other words.
// If a word is a prefix of another word, only its end flag should be unset.


#include <string>
using namespace std;

// Trie Node definition
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

    // Recursive helper to check if node has any children
    bool hasNoChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++)
            if (node->children[i])
                return false;
        return true;
    }

    // Recursive helper for deletion
    bool deleteHelper(TrieNode* node, string& word, int depth) {
        if (!node) return false;

        // Base case: reached end of word
        if (depth == word.size()) {
            if (!node->isEnd)
                return false;  // Word not found
            node->isEnd = false;  // Unmark end of word

            // If node has no children, it can be deleted
            return hasNoChildren(node);
        }

        int idx = word[depth] - 'a';
        if (!node->children[idx])
            return false;  // Word not found

        bool shouldDeleteChild = deleteHelper(node->children[idx], word, depth + 1);

        // If true → delete the child node
        if (shouldDeleteChild) {
            delete node->children[idx];
            node->children[idx] = nullptr;

            // Check if current node is also deletable
            return !node->isEnd && hasNoChildren(node);
        }

        return false;
    }

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

    // Search for a word in the Trie
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

    // Check if any word starts with given prefix
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

    // Delete a word from the Trie
    void deleteWord(string word) {
        deleteHelper(root, word, 0);
    }
};
