//
//  main.cpp
//  246.Strobogrammatic Number
//
//  Created by Abysman on 2018/12/22.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> record{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int l = 0, r = num.length() - 1;
        while (l <= r) {
            if (record[num[l++]] != num[r--]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
