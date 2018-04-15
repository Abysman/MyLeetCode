//
//  main.cpp
//  279.Perfect Squares
//
//  Created by Abysman on 2018/4/10.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>

#define MAX 0x3f3f3f3f

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n < 0) {
            return 0;
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int e = (int)sqrt(n);
        for (int i = 1; i <= e; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }

//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j * j <= i; j++) {
//                dp[i] =
//                    min(dp[i], dp[i - j*j] + 1);
//            }
//        }
        return dp.back();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    int n = 12;
    cout << s.numSquares(n) << endl;
    return 0;
}
