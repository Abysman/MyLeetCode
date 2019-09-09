//
//  main.cpp
//  161.One Edit Distance
//
//  Created by stevenxu on 9/8/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        if (s_len > t_len) return isOneEditDistance(t, s);
        if (t_len - s_len > 1 || s == t) return false;
        for (int i = 0; i < s_len; ++i) {
            if (s[i] != t[i]) {
                if (s_len == t_len) s[i] = t[i];
                else s.insert(i, 1, t[i]);
                break;
            }
        }
        return s == t || s + t[t_len - 1] == t;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
