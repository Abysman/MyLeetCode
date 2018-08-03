//
//  main.cpp
//  283.Move Zeroes
//
//  Created by Abysman on 2018/8/3.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};

//  mine
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int flag = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                count++;
                flag = i;
            }
            else {
                if (count > 0) {
                    nums[flag - count + 1] = nums[i];
                    nums[i] = 0;
                    flag = i;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
