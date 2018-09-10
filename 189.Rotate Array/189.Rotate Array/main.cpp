//
//  main.cpp
//  189.Rotate Array
//
//  Created by Abysman on 2018/9/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > 0) {
            int K = k % nums.size();
            int n = nums.size();
            reverse(nums.begin(), nums.begin() + n - K);
            reverse(nums.begin() + n - K, nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
