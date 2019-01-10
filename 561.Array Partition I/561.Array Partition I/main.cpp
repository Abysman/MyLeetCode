//
//  main.cpp
//  561.Array Partition I
//
//  Created by Abysman on 2019/1/10.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) res += nums[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
