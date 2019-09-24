//
//  main.cpp
//  Find Kth Missing Number_Lyft
//
//  Created by stevenxu on 9/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;;
// 给一个已排好序的正整数数组，在首尾之间，不连续的部分可以看成是漏掉了一些数。这些漏掉的数可以组成一个虚拟的数组，要求给出一个序号k，返回虚拟数组的第k个数。比如给定原数组：[2,4,7,8,9,15]，漏掉的数组成这样一个虚拟数组：[3,5,6,10,11,12,13,14]。若k=2，返回虚拟数组的第二个数“5”。

int findKthMissingNumber(vector<int> nums, int k) {
    if (nums.size() < 2) return -1;
    int l = 0, r = nums.size() - 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        int missingNums = (nums[mid] - nums[l]) - (mid - l);
        if (missingNums >= k) {
            r = mid;
        } else {
            k -= missingNums;
            l = mid;
        }
    }
    return nums[l] + k >= nums[r] ? -1 : nums[l] + k;
}

int main(int argc, const char * argv[]) {
    vector<int> t = {2, 4, 7, 8, 9, 15};
    int k = 2;
    vector<int> input = {2,4,9,10,11,15};
    for (int i = 0; i < 16; ++i) {
        cout << findKthMissingNumber(input, i + 1) << endl;
    }
}
