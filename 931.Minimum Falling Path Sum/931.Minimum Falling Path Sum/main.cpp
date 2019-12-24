//
//  main.cpp
//  931.Minimum Falling Path Sum
//
//  Created by stevenxu on 12/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> dp = A;
        int m = A.size(), n = A[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + A[i][j];
                } else if (j == n - 1) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + A[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + A[i][j];
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = min(res, dp[m - 1][i]);
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
