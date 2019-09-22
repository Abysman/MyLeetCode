//
//  main.cpp
//  1007.Minimum Domino Rotations For Equal Row
//
//  Created by stevenxu on 9/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = INT_MAX;

        res = min(res, helper(A, B, A[0]));
        res = min(res, helper(B, A, A[0]));
        res = min(res, helper(B, A, B[0]));
        res = min(res, helper(A, B, B[0]));
        
        return res == INT_MAX ? -1 : res;
    }
    
    int helper(vector<int> A, vector<int> B, int n) {
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == n) continue;
            if (B[i] != n) return INT_MAX;
            res++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
