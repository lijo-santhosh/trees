#include "Autocomplete.h"
#include <string>   

    
Autocomplete::Autocomplete() {
    root = new TrieNode();
}

    
void Autocomplete::insert(std::string word) {
    TrieNode* currentNode = root;


    for (char c : word) {
    int in = c - 'a';
        if (currentNode->children[in] == nullptr) {
            currentNode->children[in] = new TrieNode();
        }
        currentNode = currentNode->children[in];
    }


    currentNode->isEndOfWord = true;
}



std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    TrieNode* currentNode = root;
    std::vector<std::string> suggestions;
    for (char c : partialWord) {
      int in = c - 'a';
      if (currentNode->children[in] == nullptr) {
        return suggestions;  
      }
      currentNode = currentNode->children[in];
    }

    getWords(partialWord, currentNode, suggestions);

    return suggestions;  
  }




void Autocomplete::getWords(std::string builtWord, TrieNode* current, std::vector<std::string>& suggestions) {
    if (current->isEndOfWord == true) {
      suggestions.push_back(builtWord);
    }



    
    for (int i = 0; i < 26; i++) {
      if (current->children[i] != nullptr) { 
        std::string newWord = builtWord;
        newWord.push_back('a' + i);
        getWords(newWord, current->children[i], suggestions); 
      }
    }
}

