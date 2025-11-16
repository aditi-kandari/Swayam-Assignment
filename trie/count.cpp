// Problem Statement : 

// Count the number of nodes in the trie data structure

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

// Helper function to count words in the Trie

int countWords(TrieNode* node) {
    if (!node) return 0;

    int count = 0;
    if (node->isEnd)
        count++;  // Count this word

    // Recur for all children
    for (int i = 0; i < 26; i++) {
        if (node->children[i])
            count += countWords(node->children[i]);
    }

    return count;
}

int totalWords(TrieNode* root) {
    return countWords(root);
}


