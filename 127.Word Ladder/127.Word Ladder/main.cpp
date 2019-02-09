//
//  main.cpp
//  127.Word Ladder
//
//  Created by Abysman on 2019/2/9.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> toVisit;
        unordered_set<string> wordDict;
        for (string w: wordList) {
            wordDict.insert(w);
        }
        helper(beginWord, wordDict, toVisit);
        int res = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; ++i) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return res;
                helper(word, wordDict, toVisit);
            }
            res++;
        }
        return 0;
    }
    
    void helper(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for (int i = 0; i < (int)word.size(); ++i) {
            char originLetter = word[i];
            for (int j = 0; j < 26; ++j) {
                word[i] = 'a' + j;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = originLetter;
        }
    }
};

// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
//         wordDict.insert(endWord);
//         queue<string> toVisit;
//         addNextWords(beginWord, wordDict, toVisit);
//         int dist = 2;
//         while (!toVisit.empty()) {
//             int num = toVisit.size();
//             for (int i = 0; i < num; i++) {
//                 string word = toVisit.front();
//                 toVisit.pop();
//                 if (word == endWord) return dist;
//                 addNextWords(word, wordDict, toVisit);
//             }
//             dist++;
//         }
//     }
// private:
//     void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
//         wordDict.erase(word);
//         for (int p = 0; p < (int)word.length(); p++) {
//             char letter = word[p];
//             for (int k = 0; k < 26; k++) {
//                 word[p] = 'a' + k;
//                 if (wordDict.find(word) != wordDict.end()) {
//                     toVisit.push(word);
//                     wordDict.erase(word);
//                 }
//             }
//             word[p] = letter;
//         }
//     }
// };

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
