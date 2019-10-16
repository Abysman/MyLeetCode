//
//  main.cpp
//  581.Shortest Unsorted Continuous Subarray
//
//  Created by stevenxu on 10/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1]) left++;
        if (left == n - 1) return 0;
        while (right > 0 && nums[right] >= nums[right - 1]) right--;
        int lmin = INT_MAX, rmax = INT_MIN;
        for (int i = left; i <= right; ++i) {
            if (nums[i] > rmax) rmax = nums[i];
            if (nums[i] < lmin) lmin = nums[i];
        }
        while (left >= 0 && nums[left] > lmin) left--;
        while (right < n && nums[right] < rmax) right++;
        return right - left - 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
