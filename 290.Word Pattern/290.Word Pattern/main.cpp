//
//  main.cpp
//  290.Word Pattern
//
//  Created by Abysman on 2018/8/28.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> pm;
        map<string, int> sm;
        istringstream is(str);
        string s;
        int i = 0;
        while (is >> s) {
            if (pm[pattern[i]] != sm[s] || i == pattern.length()) return false;
            pm[pattern[i]] = sm[s] = i + 1;
            i++;
        }
        return (i == pattern.length());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
