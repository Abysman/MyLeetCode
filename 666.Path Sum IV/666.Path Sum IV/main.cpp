//
//  main.cpp
//  666.Path Sum IV
//
//  Created by stevenxu on 9/17/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

// https://leetcode.com/problems/path-sum-iv/discuss/106887/C%2B%2B-Java-Clean-Code
class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<int> tmp(8, 0);
        vector<vector<int>> m(5, tmp);
        for (int n : nums) {
            int i = n / 100; // i is 1 based index;
            int j = (n % 100) / 10 - 1; // j used 0 based index;
            int v = n % 10;
            m[i][j] = m[i - 1][j / 2] + v;
        }
        
        int sum = 0;
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 8; j++) {
                if (i == 4 || m[i][j] && !m[i + 1][j * 2] && !m[i + 1][j * 2 + 1]){
                    sum += m[i][j];
                }
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
