#include "Trie.h"

TrieNode::TrieNode() : isEndOfWord(false) {}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->isEndOfWord = true;
}

std::vector<std::string> Trie::autocomplete(const std::string& prefix) const {
    std::vector<std::string> suggestions;
    TrieNode* current = root;

    for (char ch : prefix) {
        if (current->children.find(ch) == current->children.end()) {
            return suggestions;
        }
        current = current->children[ch];
    }

    std::string currentPrefix = prefix;
    autocompleteHelper(current, currentPrefix, suggestions);

    return suggestions;
}

void Trie::autocompleteHelper(TrieNode* node, std::string& current, std::vector<std::string>& suggestions) const {
    if (node->isEndOfWord) {
        suggestions.push_back(current);
    }

    for (const auto& pair : node->children) {
        current.push_back(pair.first);
        autocompleteHelper(pair.second, current, suggestions);
        current.pop_back();
    }
}
