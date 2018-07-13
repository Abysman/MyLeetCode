//
//  main.cpp
//  27.Remove Element
//
//  Created by Abysman on 2018/7/13.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = nums.size();
        int total = 0;
        for (int i = 0;i < l;i++) {
            if (nums[i] == val) {
                total++;
            }
            else {
                nums[i-total] = nums[i];
            }
        }
        return l - total;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
