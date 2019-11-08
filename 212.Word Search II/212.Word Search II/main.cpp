//
//  main.cpp
//  212.Word Search II
//
//  Created by stevenxu on 11/8/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Trie {
public:
    bool isWord = false;
    unordered_map<char, Trie*> next;
    
    Trie() {
    }
    
    void insert(string word) {
        Trie *curr = this;
        for (char c: word) {
            if (curr->next.find(c) == curr->next.end()) curr->next[c] = new Trie();
            curr = curr->next[c];
        }
        curr->isWord = true;
    }
    
    int search(string word) {
        Trie *curr = this;
        for (char c: word) {
            if (curr->next.find(c) == curr->next.end()) return false;
            curr = curr->next[c];
        }
        return curr->isWord;
    }
};
class Solution {
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *t = new Trie();
        unordered_set<string> res;
        for (string word: words) {
            t->insert(word);
        }
        string curr;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                helper(board, res, t, i, j, curr);
            }
        }
        return vector<string> (res.begin(), res.end());
    }
    
    void helper(vector<vector<char>>& board, unordered_set<string>& res, Trie *root, int i, int j, string curr) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (root->next.find(board[i][j]) == root->next.end()) return;
        curr += board[i][j];
        root = root->next[board[i][j]];
        if (root->isWord) {
            res.insert(curr);
        }
        char tmp = board[i][j];
        board[i][j] = '0';
        for (vector<int> dir: dirs) {
            int nextI = i + dir[0], nextJ = j + dir[1];
            helper(board, res, root, nextI, nextJ, curr);
        }
        board[i][j] = tmp;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
