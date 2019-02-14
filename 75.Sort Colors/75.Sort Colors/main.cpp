//
//  main.cpp
//  75.Sort Colors
//
//  Created by Abysman on 2018/8/12.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        int r = 0, b = nums.size() - 1;
//        for (int i = 0; i < nums.size(); ++i) {
//            while (nums[i] == 2 && i < b) swap(nums[i], nums[b--]);
//            while (nums[i] == 0 && i > r) swap(nums[i], nums[r++]);
//        }
//    }
//};

//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        int r = -1, w = -1, b = -1;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (nums[i] == 0) {
//                nums[++b] = 2;
//                nums[++w] = 1;
//                nums[++r] = 0;
//            }
//            else if (nums[i] == 1) {
//                nums[++b] = 2;
//                nums[++w] = 1;
//            }
//            else if (nums[i] == 2) nums[++b] = 2;
//        }
//    }
//};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3, -1);
        for (int i = 0; i < nums.size(); ++i) {
            if (v[nums[i]] < 0) v[nums[i]] = i;
            int curr = i;
            for (int j = 2; j > nums[curr]; j--) {
                if (nums[curr] == j || v[j] < 0) continue;
                else {
                    v[nums[curr]] = min(v[nums[curr]], v[j]);
                    swap(nums[curr], nums[v[j]]);
                    curr = v[j];
                    v[j]++;
                }
                
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0,0,2,2,1,0};
    Solution sol = Solution();
    sol.sortColors(nums);
    return 0;
}
