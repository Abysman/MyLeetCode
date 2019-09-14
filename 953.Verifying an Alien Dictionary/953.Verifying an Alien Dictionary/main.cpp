//
//  main.cpp
//  953.Verifying an Alien Dictionary
//
//  Created by stevenxu on 9/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> tmp(26);
        for (int i = 0; i < order.size(); ++i) {
            tmp[order[i] - 'a'] = i;
        }
        for (string &word: words) {
            for (char &c: word) {
                c = tmp[c - 'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
