//
//  main.cpp
//  837.New 21 Game
//
//  Created by stevenxu on 10/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  elegant sliding window
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1;
        vector<double> dp(N + 1);
        dp[0] = 1;
        double wSum = 1.0, res = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = wSum / W;
            if (i < K) wSum += dp[i];
            else res += dp[i];
            if (i >= W) wSum -= dp[i - W];
        }
        return res;
    }
};

//  my dp
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (N < K) return 1;
        vector<double> dp(K + W);
        for (int i = 1; i <= W; ++i) {
            if (K - 1 + i > N) dp[K - 1 + i] = 0;
            else dp[K - 1 + i] = 1;
        }
        for (int i = K - 1; i >= 0; --i) {
            for (int j = 1; j <= W; ++j) {
                dp[i] += dp[i + j] * 1.0 / W;
            }
        }
        return dp[0];
    }
};

//  dfs
class Solution {
public:
    double new21Game(int N, int K, int W) {
        double res = helper(N, K, W, 0);
        return res;
    }
     
    double helper(int N, int K, int W, int sum) {
        if (sum >= K && sum <= N) return 1;
        if (sum >= K && sum > N) return 0;
        double res = 0;
        for (int i = 1; i <= W; ++i) {
            int curr = sum + i;
            double tmp = helper(N, K, W, curr);
            res += (1.0 / W) * tmp;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
