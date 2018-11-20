//
//  main.cpp
//  4.Median of Two Sorted Arrays
//
//  Created by Abysman on 2018/11/19.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int res;
        int m = nums1.size();
        int n = nums2.size();
        int k = (m + n) / 2;
        if ((m + n) % 2 == 0) {
            double a = helper(nums1, 0, nums2, 0, k);
            double b = helper(nums1, 0, nums2, 0, k + 1);
            return (a + b ) / 2.0;
        }
        else return helper(nums1, 0, nums2, 0, k + 1);
    }
    
    double helper(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) return helper(nums2, j, nums1, i, k);
        if (i == nums1.size()) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int curri = min(i + k / 2, int(nums1.size())), currj = j + k / 2;
        if (nums1[curri - 1] > nums2[currj - 1]) {
            return helper(nums1, i, nums2, currj, k - k / 2);
        }
        else return helper(nums1, curri, nums2, j, k - (curri - i));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
