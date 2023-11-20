#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
};

class Trie {
public:
    Trie();
    void insert(const std::string& word);
    std::vector<std::string> autocomplete(const std::string& prefix) const;

private:
    TrieNode* root;

    void autocompleteHelper(TrieNode* node, std::string& current, std::vector<std::string>& suggestions) const;
};

#endif // TRIE_H
