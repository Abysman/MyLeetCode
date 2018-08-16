//
//  main.cpp
//  33.Search in Rotated Sorted Array
//
//  Created by Abysman on 2018/8/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//int search(vector<int>& nums, int target) {
//    int lo = 0, hi = nums.size();
//    while (lo < hi) {
//        int mid = (lo + hi) / 2;
//        
//        double num = (nums[mid] < nums[0]) == (target < nums[0])
//        ? nums[mid]
//        : target < nums[0] ? -INFINITY : INFINITY;
//        
//        if (num < target)
//            lo = mid + 1;
//        else if (num > target)
//            hi = mid;
//        else
//            return mid;
//    }
//    return -1;
//}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) return mid;
            if (nums[l] < nums[r]) {
                if (target < nums[l] || target > nums[r]) {
                    return -1;
                }
                else {
                    if (nums[mid] > target) r = mid - 1;
                    else l = mid + 1;
                }
            }
            if (nums[l] > nums[r]) {
                if (nums[mid] > nums[r]) {
                    if (target > nums[mid] || target < nums[l]) l = mid + 1;
                    else r = mid - 1;
                }
                else {
                    if (target > nums[r] || target < nums[mid]) {
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
