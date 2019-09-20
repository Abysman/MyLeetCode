//
//  main.cpp
//  300.Longest Increasing Subsequence
//
//  Created by stevenxu on 9/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>


//  O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int num: nums) {
            auto it = lower_bound(res.begin(), res.end(), num);
            if (it == res.end()) res.push_back(num);
            else *it = num;
        }
        return res.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n, INT_MAX);
        for (int num: nums) {
            for (int i = 0; i < n; ++i) {
                if (num <= tmp[i]) {
                    tmp[i] = num;
                    break;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (tmp[i] != INT_MAX) return i + 1;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
