//
//  main.cpp
//  1223.Dice Roll Simulation
//
//  Created by stevenxu on 10/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        long long MOD = 1e9+7;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16, 0)));
        for(int i = 0; i < 6; ++i) {
            dp[0][i][1] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    if (j == k) continue;
                    for (int m = 1; m <= rollMax[k]; ++m) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][m]) % MOD;
                    }
                }
                for(int m = 2; m <= rollMax[j]; ++m) {
                    dp[i][j][m] = dp[i - 1][j][m - 1];
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < 6; ++i) {
            for(int j = 1; j <= rollMax[i]; ++j) {
                answer = (answer + dp[n - 1][i][j]) % MOD;
            }
        }
        return answer;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
