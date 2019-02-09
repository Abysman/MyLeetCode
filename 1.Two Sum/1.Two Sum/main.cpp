//
//  main.cpp
//  1.Two Sum
//
//  Created by Abysman on 2019/2/8.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> record;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (record.find(nums[i]) != record.end()) {
                res.push_back(record[nums[i]]);
                res.push_back(i);
                return res;
            }
            record[target - nums[i]] = i;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
