//
//  main.cpp
//  562.Longest Line of Consecutive One in Matrix
//
//  Created by Abysman on 2018/11/27.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

//  straightforward
//  https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/discuss/102264/JavaC%2B%2B-Clean-Code-No-Cache
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size();
        int maxl = 0, hori = 0, vert = 0, inc = 0, desc = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0, hori = 0; j < n; j++, maxl = max(maxl, hori))
                hori = M[i][j] ? hori + 1 : 0;
        
        for (int j = 0; j < n; j++)
            for (int i = 0, vert = 0; i < m; i++, maxl = max(maxl, vert))
                vert = M[i][j] ? vert + 1 : 0;
        
        for (int k = 0; k < m + n; k++) {
            for (int i = min(k, m - 1), j = max(0, k - m), inc = 0; i >= 0 && j < n; i--, j++, maxl = max(maxl, inc))
                inc = M[i][j] ? inc + 1 : 0;
            for (int i = max(m - 1 - k, 0), j = max(0, k - m), desc = 0; i < m && j < n; i++, j++, maxl = max(maxl, desc))
                desc = M[i][j] ? desc + 1 : 0;
        }
        return maxl;
    }
};


//  dp
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int r = M.size();
        int c = r ? M[0].size() : 0;
        int res = 0;
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (4, 0)));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (M[i][j] == 1) {
                    res = max(res, dp[i][j][0] = 1 + (i?dp[i-1][j][0]:0));
                    res = max(res, dp[i][j][1] = 1 + (j?dp[i][j-1][1]:0));
                    res = max(res, dp[i][j][2] = 1 + (i&&j?dp[i-1][j-1][2]:0));
                    res = max(res, dp[i][j][3] = 1 + (i&&(j < c - 1)?dp[i-1][j+1][3]:0));
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
