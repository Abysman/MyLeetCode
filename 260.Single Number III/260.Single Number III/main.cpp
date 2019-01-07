//
//  main.cpp
//  260.Single Number III
//
//  Created by Abysman on 2019/1/7.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int xor_num = 0;
        for (int num:nums) {
            xor_num ^= num;
        }
        xor_num &= -xor_num;
        for (int num:nums) {
            if ((num & xor_num) == 0) res[0] ^= num;
            else res[1] ^= num;
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
