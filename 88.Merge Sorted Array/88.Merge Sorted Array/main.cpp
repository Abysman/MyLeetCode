//
//  main.cpp
//  88.Merge Sorted Array
//
//  Created by Abysman on 2018/8/2.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < m; ++i) {
            cout << "nums1:" << nums1[i] << "\n";
            if (nums1[i] <= nums2[0]) {
                continue;
            }
            if (nums1[i] >= nums2[nums2.size() - 1]) {
                swap(nums1[i], nums2[nums2.size() - 1]);
                continue;
            }
            for (int j = 0; j < nums2.size(); ++j) {
                cout << "nums2:" << nums2[j] << "\n";
                if (nums1[i] >= nums2[j]) {
                    swap(nums1[i], nums2[j]);
                    i--;
                    break;
                }
            }
        }
        for (int k = 0; k < nums2.size(); ++k) {
            nums1[m + k] = nums2[k];
        }
    }
    
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2, 5, 6};
    Solution sol = Solution();
    sol.merge(a, 3, b, b.size());
    for (auto t:a) {
        cout << t << "\n";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
