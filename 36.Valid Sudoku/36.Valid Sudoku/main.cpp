//
//  main.cpp
//  36.Valid Sudoku
//
//  Created by stevenxu on 9/17/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<pair<char, int>> rows, cols, boxes;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (!rows.insert({board[i][j], i}).second) {
                        return false;
                    }
                    if (!cols.insert({board[i][j], j}).second) {
                        return false;
                    }
                    int boxNum = 3 * (i / 3) + j / 3;
                    if (!boxes.insert({board[i][j], boxNum}).second) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
