#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        
        // Convert word to lowercase
        char ch = tolower(word[0]);
        int index = ch - 'a';
        
        TrieNode* child;
        // Check if character exists
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // If absent, create a new node
            child = new TrieNode(ch);
            root->children[index] = child;
        }
        // Recursion
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word) {
        insertUtil(root, word);
    }
    
    void printSuggestion(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != nullptr) {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
   
    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        
        // Convert str to lowercase
        for (char& c : str) {
            prefix.push_back(tolower(c));
            TrieNode* curr = prev->children[c - 'a'];
            
            if (curr == nullptr) {
                break;
            }
            
            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            output.push_back(temp);
            
            prev = curr;
        }
        return output;
    }
};



vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
      //creation of trie
      Trie* t=new Trie();

      //insert all contact in trie
      for(int i=0;i<contactList.size();i++){
          string str=contactList[i];
          t->insertWord(str);
      }

      //return ans;
     
     return t->getSuggestions(queryStr);
}
