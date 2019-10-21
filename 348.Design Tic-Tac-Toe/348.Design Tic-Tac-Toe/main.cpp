//
//  main.cpp
//  348.Design Tic-Tac-Toe
//
//  Created by stevenxu on 10/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int N;
    int diagonal = 0;
    int anti_diagonal = 0;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n);
        cols.resize(n);
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = (player == 1 ? 1 : -1);
        rows[row] += add;
        cols[col] += add;
        if (row == col) diagonal += add;
        if (row + col == N - 1) anti_diagonal += add;
        if (abs(rows[row]) == N || abs(cols[col]) == N || abs(diagonal) == N || abs(anti_diagonal) == N) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
