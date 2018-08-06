//
//  main.cpp
//  198.House Robber
//
//  Created by Abysman on 2018/8/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> res(nums.size(), 0);
        res[0] = nums[0];
        res[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); ++i) {
            res[i] = max((nums[i] + res[i - 2]), res[i-1]);
        }
        return res[nums.size() - 1];
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
