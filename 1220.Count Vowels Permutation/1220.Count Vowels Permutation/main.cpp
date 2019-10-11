//
//  main.cpp
//  1220.Count Vowels Permutation
//
//  Created by stevenxu on 10/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    vector<vector<int>> couldBeAfter = {{1,2,4},{0,2},{1,3},{2},{2,3}};
public:
    int countVowelPermutation(int n) {
        long long res = 0;
        int MOD = 1e9+7;
        vector<long long> vowels(5, 1), vowelsCopy;
        while (--n) {
            vowelsCopy = vowels;
            for (int i = 0; i < 5; ++i) {
                vowels[i] = 0;
                for (int num: couldBeAfter[i]) {
                    vowels[i] += vowelsCopy[num], vowels[i] %= MOD;
                }
            }
        }
        for (long long i: vowels) {
            res += i, res %= MOD;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
