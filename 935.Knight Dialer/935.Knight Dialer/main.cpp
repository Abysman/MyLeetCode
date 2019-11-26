//
//  main.cpp
//  935.Knight Dialer
//
//  Created by stevenxu on 11/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
    
public:
    int knightDialer(int N) {
        vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        vector<int> dp(10, 1), tmp(10);
        static int MOD = 1e9 + 7;
        while (--N > 0) {
            tmp = dp;
            for (auto i = 0; i < dp.size(); ++i) {
                dp[i] = 0;
                for (int j = 0; j < ms[i].size(); ++j) dp[i] = (tmp[ms[i][j]] + dp[i]) % MOD;
            }
        }
        return accumulate(begin(dp), end(dp), 0, [](int s, int n) {return (s + n) % MOD;});
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
