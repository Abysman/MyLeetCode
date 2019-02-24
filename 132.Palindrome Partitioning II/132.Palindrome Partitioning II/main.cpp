//
//  main.cpp
//  132.Palindrome Partitioning II
//
//  Created by Abysman on 2019/2/23.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> res(len + 1, 0);
        for (int i = 0; i <= len; ++i) res[i] = i - 1;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; i -j >= 0 && i + j < len && s[i - j] == s[i + j]; ++j) {
                res[i + j + 1] = min(res[i + j + 1], res[i - j] + 1);
            }
            for (int j = 1; i - j + 1 >= 0 && i + j < len && s[i - j + 1] == s[i + j]; ++j) {
                res[i + j + 1] = min(res[i + j + 1], res[i - j + 1] + 1);
            }
        }
        return res[len];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
