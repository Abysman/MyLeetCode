//
//  main.cpp
//  137.Single Number II
//
//  Created by Abysman on 2019/1/7.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

//  referenced from https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        int b=0;
        for(int c:nums){
            int ta=(~a&b&c)|(a&~b&~c);
            b=(~a&~b&c)|(~a&b&~c);
            a=ta;
        }
        return a|b;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
