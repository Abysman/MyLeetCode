//
//  main.cpp
//  1218.Longest Arithmetic Subsequence of Given Difference
//
//  Created by stevenxu on 10/6/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> record;
        int res = 1;
        for (int i = 0; i < arr.size(); ++i) {
            int last = arr[i] - difference;
            int curr = record.find(last) == record.end() ? 1 : record[last] + 1;
            res = max(res, curr);
            record[arr[i]] = curr;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
