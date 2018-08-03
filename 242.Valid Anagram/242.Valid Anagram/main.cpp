//
//  main.cpp
//  242.Valid Anagram
//
//  Created by Abysman on 2018/8/3.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> tmp(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            tmp[int(s[i]) - int('a')] += 1;
            tmp[int(t[i]) - int('a')] -= 1;
        }
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] < 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
