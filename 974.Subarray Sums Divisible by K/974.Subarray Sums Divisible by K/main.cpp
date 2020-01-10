//
//  main.cpp
//  974.Subarray Sums Divisible by K
//
//  Created by stevenxu on 1/10/20.
//  Copyright © 2020 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
    int MOD(int m, int n) {
        return (m % n + n) % n;
    }
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size(), currSum = 0, res = 0;
        vector<int> count(K);
        count[0] = 1;
        for (int i = 0; i < n; ++i) {
            currSum = MOD(currSum + A[i], K);
            res += count[currSum]++;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
