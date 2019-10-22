//
//  main.cpp
//  37.Sudoku Solver
//
//  Created by stevenxu on 10/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
    
    bool helper(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return helper(board, i + 1, 0);
        if (board[i][j] != '.') return helper(board, i, j + 1);
        for (char c = '1'; c <= '9'; ++c) {
            if (check(board, i , j, c)) {
                board[i][j] = c;
                if (helper(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    
    bool check(vector<vector<char>>& board, int i, int j, char c) {
        for (int h = 0; h < 9; ++h) {
            if (board[i][h] == c) return false;
            if (board[h][j] == c) return false;
            if (board[i - i%3 + h%3][j - j%3 + h/3] == c) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
