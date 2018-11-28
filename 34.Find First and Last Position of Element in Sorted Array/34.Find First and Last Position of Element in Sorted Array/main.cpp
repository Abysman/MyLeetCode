//
//  main.cpp
//  34.Find First and Last Position of Element in Sorted Array
//
//  Created by Abysman on 2018/11/27.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, h = nums.size(), mid = 0;
        int first = h, last = -1;
        while (l < h) {
            mid = l + (h - l) / 2;
            if (nums[mid] < target) l = mid + 1;
            else h = mid;
        }
        first = l;
        h = nums.size();
        while (l < h) {
            mid = l + (h - l) / 2;
            if (nums[mid] <= target) l = mid + 1;
            else h = mid;
        }
        last = h;
        if (first == last) return res;
        res[1] = last - 1;
        res[0] = first;
        return res;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
