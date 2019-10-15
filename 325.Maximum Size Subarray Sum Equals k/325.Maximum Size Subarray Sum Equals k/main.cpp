//
//  main.cpp
//  325.Maximum Size Subarray Sum Equals k
//
//  Created by stevenxu on 10/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int n = nums.size(), res = 0, currSum = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            currSum += nums[i];
            if (currSum == k) {
                res = max(res, i + 1);
            } else if (m.find(currSum - k) != m.end()) {
                res = max(res, i - m[currSum - k]);
            }
            if (m.find(currSum) == m.end()){
                m[currSum] = i;
            }
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    vector<int> tests = {1, -1, 5, -2, 3};
    s.maxSubArrayLen(tests, 3);
    std::cout << "Hello, World!\n";
    return 0;
}
