//
//  main.cpp
//  293.Flip Game
//
//  Created by Abysman on 2019/1/4.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.length() <= 1) return res;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                res.push_back(s);
                s[i] = s[i + 1] = '+';
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
