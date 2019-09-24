//
//  main.cpp
//  1055.Shortest Way to Form String
//
//  Created by stevenxu on 9/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int shortestWay(string source, string target) {
        int slen = source.size(), tlen = target.size();
        vector<bool> tmp(26, false);
        for (char c: source) {
            tmp[c - 'a'] = true;
        }
        int j = 0, res = 1;
        for (int i = 0; i < tlen; ++i, ++j) {
            if (!tmp[target[i] - 'a']) return -1;
            while (j < slen && source[j] != target[i]) {
                j++;
            }
            if (j == slen) {
                j = -1;
                res++;
                i--;
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
