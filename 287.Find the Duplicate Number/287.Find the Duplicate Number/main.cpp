//
//  main.cpp
//  287.Find the Duplicate Number
//
//  Created by Abysman on 2019/1/7.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fp = 0, sp = 0;
        while (fp < nums.size()) {
            fp = nums[nums[fp]];
            sp = nums[sp];
            if (fp == sp) {
                fp = 0;
                while (fp != sp) {
                    fp = nums[fp];
                    sp = nums[sp];
                }
                return fp;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
