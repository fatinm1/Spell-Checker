#include "Trie.h"
#include <iostream>

int main() {
    /*
    The program is an autocomplete system that suggests complete words based on 
    a prefix entered by the user. It uses a data structure called a Trie, 
    which efficiently stores and retrieves words. When you run the program and 
    type in a few letters, it quickly searches through its stored words and lists all 
    words that begin with those letters. This functionality is similar to what happens when
     you start typing a word in a search engine or text editor and it suggests possible words 
     to complete your typing.
    */
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");
    trie.insert("berry");

    std::string prefix;
    std::cout << "Enter a prefix to autocomplete: ";
    std::cin >> prefix;

    std::vector<std::string> completions = trie.autocomplete(prefix);

    std::cout << "Autocomplete suggestions:" << std::endl;
    for (const std::string& word : completions) {
        std::cout << word << std::endl;
    }

    return 0;
}

