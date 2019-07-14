//
//  main.cpp
//  560.Subarray Sum Equals K
//
//  Created by stevenxu on 7/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        int res = 0, sum = 0;
        record[0] = 1;
        for (int num: nums) {
            sum += num;
            res += record[sum - k];
            record[sum] += 1;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
