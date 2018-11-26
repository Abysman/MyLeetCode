//
//  main.cpp
//  130.Surrounded Regions
//
//  Created by Abysman on 2018/11/25.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; ++i) {
            check(board, i, 0);
            check(board, i, c - 1);
        }
        for (int j = 0; j < c; ++j) {
            check(board, 0, j);
            check(board, r - 1, j);
        }
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0 ; j < c; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void check(vector<vector<char>>& board, int i, int j ) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check(board, i - 1, j);
            if (i < board.size() - 1) check(board, i + 1, j);
            if (j > 1) check(board, i, j - 1);
            if (j < board[0].size() - 1) check(board, i, j + 1);
        }
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
