//
//  main.cpp
//  88.Merge Sorted Array
//
//  Created by Abysman on 2018/8/8.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int i = m - 1, j = n - 1, tar = m + n - 1;
//        while (j >= 0) {
//            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
//        }
//    }
//};


//  mine
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int count = 0;
        while (count < n) {
            if (nums1[i] < nums2[j]) {
                nums1[nums1.size() - 1 - count] = nums2[j];
                j--;
            }
            else {
                nums1[nums1.size() - 1 - count] = nums1[i];
                i--;
            }
            count += 1;
        }
        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[i + j + 1] = nums2[j];
                j--;
            }
            else {
                nums1[i + j + 1] = nums1[i];
                i--;
            }
        }
        while (j >= 0) {
            nums1[j] = nums2[j];
            j--;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    vector<int> a = {2,0};
    vector<int> b = {1};
    sol.merge(a, 1, b, 1);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
