//
//  main.cpp
//  215.Kth Largest Element in an Array
//
//  Created by Abysman on 2018/10/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
//        return nums[k - 1];
//    }
//};


class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
