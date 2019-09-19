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

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, curr = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((nums[mid] >= nums[0] && target >= nums[0]) ||
                (nums[mid] < nums[0] && target < nums[0])) {
                curr = nums[mid];
                if (curr == target) return mid;
                else if (curr > target) high = mid - 1;
                else low = mid + 1;
            }
            else if (target < nums[0]) low = mid + 1;
            else if (target >= nums[0]) high = mid - 1;
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, mid = -1, curr;
        while (low <= high) {
            mid = low + (high - low) / 2;
            curr = nums[mid];
            if ((target < nums[0]) && (nums[mid] < nums[0]) || ((target >= nums[0]) && (nums[mid] >= nums[0]))) {
                curr = nums[mid];
            }
            else {
                if (target < nums[0]) curr = INT_MIN;
                else curr= INT_MAX;
            }
            if (target < curr) high = mid - 1;
            else if (target > curr) low = mid + 1;
            else return mid;
        }
        return -1;
    }
};


//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        if (nums.empty()) return -1;
//        int l = 0, r = nums.size() - 1;
//        while (l < r) {
//            int mid = l + (r - l) / 2;
//            if (target == nums[mid]) return mid;
//            if (nums[l] < nums[r]) {
//                if (target < nums[l] || target > nums[r]) {
//                    return -1;
//                }
//                else {
//                    if (nums[mid] > target) r = mid - 1;
//                    else l = mid + 1;
//                }
//            }
//            if (nums[l] > nums[r]) {
//                if (nums[mid] > nums[r]) {
//                    if (target > nums[mid] || target < nums[l]) l = mid + 1;
//                    else r = mid - 1;
//                }
//                else {
//                    if (target > nums[r] || target < nums[mid]) {
//                        r = mid - 1;
//                    }
//                    else l = mid + 1;
//                }
//            }
//        }
//        if (nums[l] == target) return l;
//        return -1;
//    }
//};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
