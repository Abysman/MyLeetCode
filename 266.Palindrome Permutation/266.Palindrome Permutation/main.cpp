//
//  main.cpp
//  266.Palindrome Permutation
//
//  Created by Abysman on 2018/12/22.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> r;
        int res = 0;
        for (auto c:s) {
            r[c] += 1;
        }
        for (auto it = r.begin(); it != r.end(); it++) {
            if (it->second % 2 == 1) {
                if (res == 1) return false;
                else res = 1;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
