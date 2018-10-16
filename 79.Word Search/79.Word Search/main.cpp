//
//  main.cpp
//  79.Word Search
//
//  Created by Abysman on 2018/10/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (board.empty()) return false;
        bool ans = false;
        std::vector<int> tmp(board[0].size(), 0);
        std::vector<std::vector<int>> visited(board.size(), tmp);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                ans = dfs(board, word, i, j, 0, visited);
                if (ans == true) return true;
            }
        }
        return ans;
    }
    
    bool dfs(std::vector<std::vector<char>>& board, std::string word, int i, int j, int wordIndex, std::vector<std::vector<int>>& visited) {
        bool res;
        if (wordIndex > word.length() - 1 ||
            i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1 || visited[i][j] || board[i][j] != word[wordIndex])
            return false;
        if (wordIndex == word.length() - 1) return true;
        
        visited[i][j] = 1;
        res = dfs(board, word, i + 1, j, wordIndex + 1, visited) || dfs(board, word, i - 1, j, wordIndex + 1, visited) ||
        dfs(board, word, i, j + 1, wordIndex + 1, visited) || dfs(board, word, i, j - 1, wordIndex + 1, visited);
        if (res == false) visited[i][j] = 0;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
