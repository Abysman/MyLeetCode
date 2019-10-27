//
//  main.cpp
//  1165.Single-Row Keyboard
//
//  Created by stevenxu on 10/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res = 0, pos = 0;
        unordered_map<char, int> record;
        for (int i = 0; i < keyboard.size(); ++i) {
            record[keyboard[i]] = i;
        }
        for (char c: word) {
            res += abs(record[c] - pos);
            pos = record[c];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
