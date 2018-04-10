//
//  main.cpp
//  Search a 2D Matrix II
//
//  Created by Abysman on 2018/4/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        return F(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
    bool F(vector<vector<int>>& matrix, int s_r, int s_c, int e_r, int e_c, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        if (s_c > matrix[0].size() - 1 || s_r > matrix.size() - 1 || s_r < 0 || s_c < 0 || e_r < 0 || e_c < 0) {
            return false;
        }
        int row = e_r - s_r + 1;
        int col = e_c - s_c + 1;
        if (row == col) {
            for (int i = 1; i <= row; i++) {
                if (i == 1) {
                    if (matrix[s_r][s_c] != target) {
                        continue;
                    }
                }
                if (matrix[s_r + i - 1][s_c + i - 1] < target) {
                    continue;
                }
                if (matrix[s_r + i - 1][s_c + i - 1] == target) {
                    return true;
                }
                else {
                    return (F(matrix, s_r, s_c + i - 1, s_r + i - 2, e_c, target)
                            || F(matrix, s_r + i - 1, s_c, e_r, s_c + i - 2, target));
                }
            }
            return false;
        }

        if (row < col) {
            return (F(matrix, s_r, s_c, e_r, s_c + row - 1, target)
                    || F(matrix, s_r, s_c + row, e_r, e_c, target));
        }
        
        return (F(matrix, s_r, s_c, s_r + col - 1, e_c, target)
                        || F(matrix, s_r + col, s_c, e_r, e_c, target));
    }
};

class betterSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int i = row - 1;
        int j = 0;
        while (i > 0 || j < col ) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                i--;
            }
            if (matrix[i][j] < target) {
                j++;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    vector<vector<int>> matrix1 = {{2}};
    vector<vector<int>> matrix2 = {{1,4,7},{2,5,9},{3,6,10}};
    vector<vector<int>> matrix3 = {{3,5,9,9,14},{7,8,11,15,15},{8,10,16,16,17}};
    vector<vector<int>> matrix4 = {{4,5},{4,6},{9,14},{10,15}};
    betterSolution sol = betterSolution();
    cout << sol.searchMatrix(matrix, 25) << endl;
    
}
