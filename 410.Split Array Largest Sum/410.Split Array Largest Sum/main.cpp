//
//  main.cpp
//  410.Split Array Largest Sum
//
//  Created by stevenxu on 9/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long left, right, sum = 0;
        int largest = 0;
        for (int num: nums) {
            largest = max(largest, num);
            sum += num;
        }
        left = largest, right = sum;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (valid(nums, mid, m)) right = mid - 1;
            else left = mid + 1;
        }
        return (int)left;
    }
    
    bool valid(vector<int> nums, long target, int m) {
        int count = 1;
        long total = 0;
        for (int num: nums) {
            total += num;
            if (total > target) {
                count++;
                total = num;
                if (count > m) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
