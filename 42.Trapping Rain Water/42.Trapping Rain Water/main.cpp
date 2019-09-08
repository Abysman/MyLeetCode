//
//  main.cpp
//  42.Trapping Rain Water
//
//  Created by stevenxu on 9/7/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  two pointers
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};

//  O(2n)
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int res = 0;
        if (size <= 2) return 0;
        
        vector<int> left_max(size, 0);
        left_max[0] = 0;
        vector<int> right_max(size, 0);
        right_max[size - 1] = 0;
        int curr_max = height[0];
        for (int i = 1; i <= size - 1; ++i) {
            curr_max = max(height[i], curr_max);
            left_max[i] = curr_max;
        }
        curr_max = height[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            curr_max = max(height[i], curr_max);
            right_max[i] = curr_max;
        }
        for (int i = 1; i < size - 1; ++i) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
