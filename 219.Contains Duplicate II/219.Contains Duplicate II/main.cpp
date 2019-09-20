//
//  main.cpp
//  219.Contains Duplicate II
//
//  Created by stevenxu on 9/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) {
                if (i - record[nums[i]] <= k) return true;
                else record[nums[i]] = i;
            } else {
                record[nums[i]] = i;
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
