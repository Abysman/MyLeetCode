//
//  main.cpp
//  548.Split Array with Equal Sum
//
//  Created by stevenxu on 9/17/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size(), sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        vector<int> sums = nums;
        sums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> s;
            for (int i = 1; i < j - 1; ++i) {
                if (sums[i - 1] == (sums[j - 1] - sums[i])) {
                    s.insert(sums[i - 1]);
                }
            }
            for (int k = j + 2; k < n - 1; ++k) {
                int s3 = sums[k - 1] - sums[j], s4 = sums[n - 1] - sums[k];
                if (s3 == s4 && s.count(s3)) return true;
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
