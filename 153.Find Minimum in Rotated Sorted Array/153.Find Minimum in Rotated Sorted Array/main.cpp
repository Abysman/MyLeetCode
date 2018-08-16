//
//  main.cpp
//  153.Find Minimum in Rotated Sorted Array
//
//  Created by Abysman on 2018/8/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = helper(nums, 0, nums.size() - 1);
        return min;
    }
    
    int helper(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1]) return min(nums[l], nums[mid + 1]);
        int l_min = helper(nums, l, mid);
        int r_min = helper(nums, mid + 1, r);
        return min(l_min, r_min);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
