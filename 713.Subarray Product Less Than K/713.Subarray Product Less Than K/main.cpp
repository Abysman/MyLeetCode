//
//  main.cpp
//  713.Subarray Product Less Than K
//
//  Created by stevenxu on 9/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size();
        int prod = 1, res = 0;
        
        for (;right < n; ++right) {
            prod *= nums[right];
            while (left <= right && prod >= k) prod /= nums[left++];
            res += right - left + 1;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
