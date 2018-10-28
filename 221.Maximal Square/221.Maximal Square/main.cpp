//
//  main.cpp
//  221.Maximal Square
//
//  Created by Abysman on 2018/10/27.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>


//optimized DP
//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        if (matrix.empty()) {
//            return 0;
//        }
//        int m = matrix.size(), n = matrix[0].size(), sz = 0, pre = 0;
//        vector<int> dp(m + 1, 0);
//        for (int j = 0; j < n; j++) {
//            for (int i = 1; i <= m; i++) {
//                int temp = dp[i];
//                if (matrix[i - 1][j] == '1') {
//                    dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
//                    sz = max(sz, dp[i]);
//                } else {
//                    dp[i] = 0;
//                }
//                pre = temp;
//            }
//        }
//        return sz * sz;
//    }
//};

//  DP
//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        if (matrix.empty() || matrix[0].empty()) return 0;
//        int res = 0;
//        vector<int> tmp(matrix[0].size(), 0);
//        vector<vector<int>> record(matrix.size(), tmp);
//        for (int i = 0; i < matrix.size(); ++i) {
//            record[i][0] = matrix[i][0] - '0';
//            res = max(record[i][0], res);
//        }
//        for (int i = 0; i < matrix[0].size(); ++i) {
//            record[0][i] = matrix[0][i] - '0';
//            res = max(record[0][i], res);
//        }
//        for (int i = 1; i < matrix.size(); ++i) {
//            for (int j = 1; j < matrix[0].size(); ++j) {
//                if (matrix[i][j] == '1') {
//                    record[i][j] = min(min(record[i - 1][j], record[i][j - 1]), record[i - 1][j - 1]) + 1;
//                    res = max(record[i][j], res);
//                }
//            }
//        }
//        return res * res;
//    }
//
//};

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        int curr = INT_MIN;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    curr = helper(matrix, i, j, 1);
                    res = std::max(curr, res);
                }
            }
        }
        return res * res;
    }
    
    int helper(std::vector<std::vector<char>>& matrix, int r, int c, int count) {
        while (true) {
            for (int i = 0; i < count; ++i) {
                int next_row_i = r + count;
                int next_col_j = c + count;
                
                if (next_row_i >= matrix.size() || next_col_j >= matrix[0].size()) {
                    return count;
                }
                if (matrix[next_row_i][c + i] != '1' || matrix[r + i][next_col_j] != '1') {
                    return count;
                }
            }
            if (matrix[r + count][c + count] != '1') return count;
            count++;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
