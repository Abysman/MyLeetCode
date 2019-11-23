//
//  main.cpp
//  462.Minimum Moves to Equal Array Elements II
//
//  Created by stevenxu on 11/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int minMoves2(vector<int>& nums) {
      sort(nums.begin(), nums.end()); int n = nums.size(), res = 0;
      for (int i = 0; i < n/2; ++i) res += (nums[n-1-i]-nums[i]);
      return res;
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> record(n);
        record.back() = nums.back();
        for (int i = n - 2; i >= 0; --i) {
            record[i] = record[i + 1] + nums[i];
        }
        int targetC = -1;
        long long targetF = INT_MAX;
        for (int i = 0; i < n; ++i) {
            long long curr = 2 * record[i] + (long long)(2 * i - n) * nums[i] - record[0];
            if (curr < targetF) {
                targetC = record[i];
                targetF = curr;
            }
        }
        return targetF;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
