//
//  main.cpp
//  540.Single Element in a Sorted Array
//
//  Created by stevenxu on 11/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid-1]) right = mid - 2;
                else if (nums[mid] == nums[mid+1]) left = mid + 2;
                else return nums[mid];
            }
            else {
                if (nums[mid] == nums[mid-1]) left = mid + 1;
                else if (nums[mid] == nums[mid+1]) right = mid - 1;
            }
        }
        return nums[left];
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        int i = 0, j = n - 1, mid = 0;
        while (i <= j) {
            mid = i + (j - i) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } else if ((nums[mid] == nums[mid - 1] && mid % 2 == 0) ||
                     (nums[mid] == nums[mid + 1] && mid % 2 == 1)) {
                j = mid - 1;
            } else i = mid + 1;
        }
        return nums[i];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
