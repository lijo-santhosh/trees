#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

class Autocomplete {
 private:
  struct TrieNode {
    std::vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
      isEndOfWord = false;
      children = std::vector<TrieNode*>(26, nullptr);
    }
  };

  TrieNode* root;

 public:
  Autocomplete();

  void insert(std::string word);

  std::vector<std::string> getSuggestions(std::string partialWord);

  void getWords(std::string builtWord, TrieNode* current, std::vector<std::string>& suggestions);
};

#endif
