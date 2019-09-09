//
//  main.cpp
//  16.3Sum Closest
//
//  Created by Abysman on 2018/5/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int num_size = nums.size();
        if (num_size < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < num_size - 2; ++i) {
            int left = i + 1, right = num_size - 1;
            
            while (left < right) {
                int mid = left + (right - left) / 2;
                int curr_sum = nums[i] + nums[left] + nums[right];
                if (curr_sum == target) return target;
                if (abs(curr_sum - target) < abs(res - target)) res = curr_sum;
                if (curr_sum < target) left++;
                else if (curr_sum > target) right--;
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
