//
//  main.cpp
//  565.Array Nesting
//
//  Created by stevenxu on 9/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  O(n) time complexity
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int currLen = 0;
            for (int j = i; nums[j] >= 0; currLen++) {
                int nums_j = nums[j];
                nums[j] = -1;
                j = nums_j;
            }
            res = max(res, currLen);
        }
        return res;
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.empty()) return 0;
        set<int> used;
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (used.count(nums[i]) == 0) {
                int start = i, curr = start, len = 0;
                do {
                    used.insert(curr);
                    curr = nums[curr];
                    len += 1;
                } while (curr != start);
                res = max(res, len);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
