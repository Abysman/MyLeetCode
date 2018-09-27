//
//  main.cpp
//  55.Jump Game
//
//  Created by Abysman on 2018/9/26.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

//bool canJump(int A[], int n) {
//    int i = 0;
//    for (int reach = 0; i < n && i <= reach; ++i)
//        reach = max(i + A[i], reach);
//    return i == n;
//}

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        int n = nums.size();
        vector<int> res(n);
        int max = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i + nums[i] > max) max = i + nums[i];
            else if (i + nums[i] == max && nums[i] == 0) {
                break;
            }
            
            if (i <= max) {
                res[i] = 1;
            }
        }
        if (max >= n - 1) return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
