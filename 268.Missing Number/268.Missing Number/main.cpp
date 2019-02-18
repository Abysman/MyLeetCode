//
//  main.cpp
//  268.Missing Number
//
//  Created by Abysman on 2018/8/14.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = nums.size();
        for (int i = 0; i < n; ++i) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};


//  mine
//  might cause overflow
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        return nums.size() * (nums.size() + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
//    }
//};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
