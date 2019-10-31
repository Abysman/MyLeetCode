//
//  main.cpp
//  1170.Compare Strings by Frequency of the Smallest Character
//
//  Created by stevenxu on 10/31/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size(), m = words.size();
        vector<int> queriesRecord(n), wordsRecord(m), res;
        for (int i = 0; i < n; ++i) {
            queriesRecord[i] = helper(queries[i]);
        }
        for (int j = 0; j < m; ++j) {
            wordsRecord[j] = helper(words[j]);
        }
        sort(wordsRecord.begin(), wordsRecord.end());
        for (int i = 0; i < n; ++i) {
            int curr;
            auto found = upper_bound(wordsRecord.begin(), wordsRecord.end(), queriesRecord[i]);
            if (found == wordsRecord.end()) curr = 0;
            else curr = wordsRecord.end() - found;
            res.push_back(curr);
        }
        return res;
    }
    
    int helper(string s) {
        char minChar = s[0];
        int res = 0;
        for (char c: s) {
            if (c < minChar) {
                minChar = c;
                res = 1;
            } else if (c == minChar) {
                res++;
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
