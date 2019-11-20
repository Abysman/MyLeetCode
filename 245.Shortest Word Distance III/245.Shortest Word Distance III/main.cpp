//
//  main.cpp
//  245.Shortest Word Distance III
//
//  Created by stevenxu on 11/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long res = INT_MAX, i1 = res, i2 = -res;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                i1 = i;
            }
            if (words[i] == word2) {
                if (word1 == word2) i1 = i2;
                i2 = i;
            }
            res = min(res, abs(i2 - i1));
        }
        return res;
    }
};
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        vector<int> v1, v2;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) v1.push_back(i);
            if (words[i] == word2) v2.push_back(i);
        }
        if (word1 == word2) {
            for (int i = 0; i < v1.size() - 1; ++i) {
                res = min(res, v1[i + 1] - v1[i]);
            }
            return res;
        }
        for (int i: v1) {
            auto f = lower_bound(v2.begin(), v2.end(), i);
            int left = INT_MAX, right = INT_MAX;
            if (f != v2.begin()) left = abs(*(f - 1) - i);
            if (f != v2.end()) right = abs(*f - i);
            res = min(res, min(left, right));
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
