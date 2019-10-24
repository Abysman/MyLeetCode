//
//  main.cpp
//  1048.Longest String Chain
//
//  Created by stevenxu on 10/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        int res = 0, n = words.size();
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        for (string w : words) {
            int best = 0;
            for (int i = 0; i < w.length(); i++) {
                string word = w.substr(0, i) + w.substr(i + 1);
                best = max(best, dp[word] + 1);
            }
            dp[w] = best;
            res = max(res, best);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
