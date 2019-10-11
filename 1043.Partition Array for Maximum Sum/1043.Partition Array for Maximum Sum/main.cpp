//
//  main.cpp
//  1043.Partition Array for Maximum Sum
//
//  Created by stevenxu on 10/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if (A.empty() || K == 0) return 0;
        vector<int> dp(A.size());
        int currMax = A[0];
        for (int i = 0; i < K; ++i) {
            currMax = max(currMax, A[i]);
            dp[i] = currMax * (i + 1);
        }
        for (int i = K; i < A.size(); ++i) {
            int currDp = A[i] + dp[i - 1];
            currMax = A[i];
            for (int j = 1; j < K; ++j) {
                currMax = max(currMax, A[i - j]);
                currDp = max(currDp, dp[i - j - 1] + (j + 1) * currMax);
            }
            dp[i] = currDp;
        }
        return dp[A.size() - 1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
