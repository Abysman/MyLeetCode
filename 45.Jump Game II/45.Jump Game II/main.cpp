//
//  main.cpp
//  45.Jump Game II
//
//  Created by Abysman on 2018/9/26.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int n = nums.size(), step = 0, start = 0, end = 0;
//        while (end < n - 1) {
//            step++;
//            int maxend = end + 1;
//            for (int i = start; i <= end; i++) {
//                if (i + nums[i] >= n - 1) return step;
//                maxend = max(maxend, i + nums[i]);
//            }
//            start = end + 1;
//            end = maxend;
//        }
//        return step;
//    }
//};

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int n = nums.size();
        int res = INT_MAX;
        int count = 0;
        int curr;
        for (int i = 0; i < n; ++i) {
            curr = nums[i] + i;
            int j = i;
            while (curr < n - 1) {
                j = curr;
                curr = nums[j] + j;
                count++;
            }
            if (count < res) res = count;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
