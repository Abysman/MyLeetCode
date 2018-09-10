//
//  main.cpp
//  162.Find Peak Element
//
//  Created by Abysman on 2018/9/10.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int findPeakElement(vector<int>& nums) {
//        if (nums.empty()) return INT_MIN;
//        if (nums.size() == 1) return 0;
//        int l = 0;
//        int h = nums.size() - 1;
//        while (l < h) {
//            int mid = l + (h - l) / 2;
//            if (nums[mid] < nums[mid + 1]) l = mid + 1;
//            else {
//                h = mid;
//            }
//        }
//        return l;
//    }
//};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;
        if (nums.size() == 1) return 0;
        int l = 0;
        int h = nums.size() - 1;
        int res = helper(nums, l, h);
        return res;
    }
    
    int helper(vector<int>& nums, int l, int h) {
        int mid = l + (h - l) / 2;
        if (l == h) {
            if (l == 0) {
                if (nums[l] > nums[l + 1]) {
                    return l;
                }
            }
            else if (h == nums.size() - 1)  {
                if (nums[h] > nums[h - 1]) {
                    return h;
                }
            }
            else if (nums[l] > nums[l - 1] && nums[l] > nums[l + 1]) {
                return l;
            }
            return INT_MIN;
        }
        int res_l = helper(nums, l, mid);
        if (res_l == INT_MIN) {
            int res_h = helper(nums, mid + 1, h);
            return res_h;
        }
        return res_l;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3,1};
    Solution sol = Solution();
    cout << sol.findPeakElement(a);
    std::cout << "Hello, World!\n";
    return 0;
}
