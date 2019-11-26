//
//  main.cpp
//  1269.Number of Ways to Stay in the Same Place After Some Steps
//
//  Created by stevenxu on 11/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
    
public:
    int numWays(int steps, int arrLen) {
        int sz = min(steps / 2 + 1, arrLen);
        int MOD = 1e9 + 7;
        long long last, next;
        
        vector<long> dp(sz), tmp(sz);
        dp[0] = 1;
        while (steps-- > 0) {
            tmp = dp;
            for (int j = 0; j < sz; ++j) {
                last = j == 0 ? 0 : tmp[j - 1];
                next = j == sz - 1? 0 : tmp[j + 1];
                dp[j] = (last + next + tmp[j]) % MOD;
            }
        }
        return dp[0];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
