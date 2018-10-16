//
//  main.cpp
//  280.Wiggle Sort
//
//  Created by Abysman on 2018/10/7.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i%2==1) && (nums[i]<nums[i-1]) || (i%2==0) && (nums[i]>nums[i-1])) {
                swap(nums[i], nums[i-1]);
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
