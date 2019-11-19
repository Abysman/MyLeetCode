//
//  main.cpp
//  523.Continuous Subarray Sum
//
//  Created by stevenxu on 11/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() <= 1) return false;
        k = abs(k);
        unordered_map<int, int> m;
        int sum = 0;
        if (k == 0) {
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] == 0 && nums[i + 1] == 0) return true;
            }
            return false;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum % k == 0 && i != 0) return true;
            if (m.find(sum % k) != m.end()) {
                if (i - m[sum % k] > 1) return true;
            } else {
                m[sum % k] = i;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
