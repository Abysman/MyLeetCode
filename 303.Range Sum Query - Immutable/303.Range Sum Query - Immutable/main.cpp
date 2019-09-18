//
//  main.cpp
//  303.Range Sum Query - Immutable
//
//  Created by stevenxu on 9/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        prefixSum.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            prefixSum.push_back(prefixSum[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return prefixSum[j];
        return prefixSum[j] - prefixSum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
