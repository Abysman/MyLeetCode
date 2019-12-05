//
//  main.cpp
//  416.Partition Equal Subset Sum
//
//  Created by stevenxu on 12/4/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto num : nums)
            for(int i = target; i >= num; i--)
                dp[i] = dp[i] || dp[i - num];
        return dp[target];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
