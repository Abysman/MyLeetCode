//
//  main.cpp
//  1309.Decrypt String from Alphabet to Integer Mapping
//
//  Created by stevenxu on 1/5/20.
//  Copyright © 2020 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size(), i = 0;
        string res = "";
        while (i < n) {
            if (i + 2 < n && s[i + 2] == '#') {
                res += 'j' + (stoi(s.substr(i, 2)) - 10);
                i += 3;
            } else {
                res += 'a' + (s[i] - '1');
                i++;
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
