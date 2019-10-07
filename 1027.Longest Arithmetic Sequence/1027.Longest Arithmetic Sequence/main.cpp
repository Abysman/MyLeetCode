//
//  main.cpp
//  1027.Longest Arithmetic Sequence
//
//  Created by stevenxu on 10/7/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int res = 0;
        unordered_map<int, unordered_map<int, int>> record;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int currDiff = A[j] - A[i];
                record[currDiff][j] = record[currDiff][i] != 0 ? record[currDiff][i] + 1 : 2;
                res = max(record[currDiff][j], res);
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
