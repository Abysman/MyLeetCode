//
//  main.cpp
//  211.Add and Search Word - Data structure design
//
//  Created by stevenxu on 11/19/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;;
class Trie {
public:
    unordered_map<char, Trie*> next;
    bool isWord = false;
    
    Trie() {
    }
    
    void addWords(string word) {
        Trie* curr = this;
        for (char c: word) {
            if (curr->next.find(c) == curr->next.end()) {
                curr->next[c] = new Trie();
            }
            curr = curr->next[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (char c: word) {
            if (curr->next.find(c) == curr->next.end()) return false;
            curr = curr->next[c];
        }
        return curr->isWord;
    }
};

class WordDictionary {
private:
    Trie *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->addWords(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Trie *curr = root;
        return helper(word, curr);
    }
    
    bool helper(string word, Trie* curr) {
        if (word.empty()) {
            return curr->isWord;
        }
        bool res = false;
        if (word[0] != '.') {
            if (curr->next.find(word[0]) == curr->next.end()) return false;
            res = helper(word.substr(1), curr->next[word[0]]);
        } else {
            for (auto m: curr->next) {
                if (helper(m.first + word.substr(1), curr)) return true;
            }
        }
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class Trie {
public:
    unordered_map<char, Trie*> next;
    bool isWord = false;
    
    Trie() {
    }
    
    void addWords(string word) {
        Trie* curr = this;
        for (char c: word) {
            if (curr->next.find(c) == curr->next.end()) {
                curr->next[c] = new Trie();
            }
            curr = curr->next[c];
        }
        curr->isWord = true;
    }
};

class WordDictionary {
private:
    Trie *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->addWords(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Trie *curr = root;
        return helper(word.c_str(), curr);
    }
    
    bool helper(const char *ch, Trie* curr) {
        if (!curr) return false;
        if (*ch == '\0') {
            return curr->isWord;
        }
        if (*ch != '.') {
            return helper(ch + 1, curr->next[*ch]);
        } else {
            for (auto m: curr->next) {
                if (helper(ch + 1, m.second)) return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    WordDictionary *d = new WordDictionary();
    d->addWord("bad");
    d->addWord("dad");
    d->addWord("mad");
    bool res =  d->search(".ad");
    std::cout << "Hello, World!\n";
    return 0;
}
