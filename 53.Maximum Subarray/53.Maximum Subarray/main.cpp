//
//  main.cpp
//  53.Maximum Subarray
//
//  Created by Abysman on 2018/7/25.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int tmpSum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            tmpSum = tmpSum > 0 ? tmpSum + nums[i] : nums[i];
            res = max(res, tmpSum);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
