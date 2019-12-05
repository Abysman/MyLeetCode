//
//  main.cpp
//  494.Target Sum
//
//  Created by stevenxu on 12/4/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;
        for (int num: nums) sum += num;
        return (sum + S) & 1 || sum < S ? 0 : helper(nums, (sum + S) >> 1);
    }
    
    int helper(vector<int> &nums, int target) {
        vector<long> dp(target + 1);
        dp[0] = 1;
        for (int num: nums) {
            for (long i = target; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
