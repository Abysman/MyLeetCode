//
//  main.cpp
//  209.Minimum Size Subarray Sum
//
//  Created by Abysman on 2018/11/1.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

// o(nlogn)

//class Solution {
//public:
//    int minSubArrayLen(int s, vector<int>& nums) {
//        vector<int> sums = accumulate(nums);
//        int n = nums.size(), minlen = INT_MAX;
//        for (int i = 1; i <= n; i++) {
//            if (sums[i] >= s) {
//                int p = upper_bound(sums, 0, i, sums[i] - s);
//                if (p != -1) minlen = min(minlen, i - p + 1);
//            }
//        }
//        return minlen == INT_MAX ? 0 : minlen;
//    }
//private:
//    vector<int> accumulate(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> sums(n + 1, 0);
//        for (int i = 1; i <= n; i++)
//            sums[i] = nums[i - 1] + sums[i - 1];
//        return sums;
//    }
//    int upper_bound(vector<int>& sums, int left, int right, int target) {
//        int l = left, r = right;
//        while (l < r) {
//            int m = l + ((r - l) >> 1);
//            if (sums[m] <= target) l = m + 1;
//            else r = m;
//        }
//        return sums[r] > target ? r : -1;
//    }
//};

//  o(n) sliding windows
//class Solution {
//public:
//    int minSubArrayLen(int s, vector<int>& nums) {
//        int num_len= nums.size();
//        int left=0, right=0, total=0, min_len= num_len+1;
//        while (right < num_len) {
//            // move right silder forward till total >= s
//            do { total += nums[right++]; } while (right<num_len && total< s);
//            // move left slider forward while maintaining total >= s
//            while (left<right && total-nums[left]>=s) total -= nums[left++];
//            // record if it's the minimum
//            if (total>=s && min_len> right- left)
//                min_len= right- left;
//        }
//        return min_len<=num_len ? min_len: 0;
//    }
//};


//  o(n)
class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        int start = 0, n = nums.size(), sum = 0, res = INT_MAX;
        if (n == 0) return 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            while (sum >= s) {
                res = std::min(res, i - start + 1);
                sum -= nums[start++];
            }
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
