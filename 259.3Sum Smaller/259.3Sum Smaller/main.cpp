//
//  main.cpp
//  259.3Sum Smaller
//
//  Created by stevenxu on 7/27/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0, len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i) {
            int left = i + 1, right = len - 1;
            if (nums[i] + nums[i + 1] + nums[i + 2] >= target) return res;
            while (left < right) {
                while (nums[i] + nums[left] + nums[right] >= target && left < right) right--;
                res += right -left;
                left++;
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
