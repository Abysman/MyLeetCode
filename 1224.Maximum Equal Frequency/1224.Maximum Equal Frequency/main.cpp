//
//  main.cpp
//  1224.Maximum Equal Frequency
//
//  Created by stevenxu on 10/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> freq(1e5 + 1);
        vector<int> counts(1e5 + 1);
        for (int i = 1; i <= n; ++i) {
            int curr = nums[i - 1];
            freq[counts[curr]]--;
            int c = ++counts[curr];
            ++freq[counts[curr]];
            
            if (freq[c] * c == i && i < n) res = i + 1;
            int d = i - freq[c] * c;
            if ((d == c + 1 || d == 1) && freq[d] == 1) res = i;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
