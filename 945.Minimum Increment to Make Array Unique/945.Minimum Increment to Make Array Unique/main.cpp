//
//  main.cpp
//  945.Minimum Increment to Make Array Unique
//
//  Created by stevenxu on 10/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() <= 1) return 0;
        int res = 0;
        sort(A.begin(), A.end());
        int prev = A[0];
        for (int i = 1; i < A.size(); ++i) {
            if (prev >= A[i]) {
                prev++;
                res += prev - A[i];
            } else {
                prev = A[i];
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
