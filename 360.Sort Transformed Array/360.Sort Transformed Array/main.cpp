//
//  main.cpp
//  360.Sort Transformed Array
//
//  Created by stevenxu on 9/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res(n, 0);
        int i = 0, j = n - 1;
        int index = (a >= 0? n - 1: 0);
        while (i <= j) {
            if (a >= 0) res[index--] = calc(nums[i], a, b, c) >= calc(nums[j], a, b, c) ? calc(nums[i++], a, b, c) : calc(nums[j--], a, b, c);
            else res[index++] = calc(nums[i], a, b, c) >= calc(nums[j], a, b, c) ? calc(nums[j--], a, b, c) : calc(nums[i++], a, b, c);
        }
        return res;
    }
    
    int calc(int num, int a, int b, int c) {
        return a * num * num + b * num + c;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
