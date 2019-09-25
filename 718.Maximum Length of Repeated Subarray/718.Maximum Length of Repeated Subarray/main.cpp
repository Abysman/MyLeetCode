//
//  main.cpp
//  718.Maximum Length of Repeated Subarray
//
//  Created by stevenxu on 9/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>


/**
* dp[i][j] = a[i] == b[j] ? 1 + dp[i + 1][j + 1] : 0;
* dp[i][j] : max lenth of common subarray start at a[i] & b[j];
*/
class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if (!m || !n) return 0;
        vector<int> dp(n + 1);
        int res = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp[j] = a[i] == b[j] ? 1 + dp[j + 1] : 0);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int la = A.size();
        int lb = B.size();
        vector<vector<int> > dp( la + 1, vector<int>( lb + 1, 0 ) );
        int res = 0;
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                if (A[i - 1] == B[j- 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > res) res = dp[i][j];
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
