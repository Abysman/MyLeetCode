//
//  main.cpp
//  525.Contiguous Array
//
//  Created by stevenxu on 10/7/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0, currSum = 0;
        unordered_map<int, int> record;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) nums[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            currSum += nums[i];
            if (currSum == 0) res = max(res, i + 1);
            if (record.find(currSum) != record.end()) {
                res = max(res, i - record[currSum]);
            } else {
                record[currSum] = i;
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
