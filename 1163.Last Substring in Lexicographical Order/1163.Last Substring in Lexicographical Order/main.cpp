//
//  main.cpp
//  1163.Last Substring in Lexicographical Order
//
//  Created by stevenxu on 10/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, len = s.size(), i = 1;
        while (i < len) {
            if (s[i] > s[start]) {
                start = i;
            } else if (s[i] == s[start]) {
                int curr = i, j = start;
                while (i < len && j < curr && s[i] == s[j]) {
                    i++;
                    j++;
                }
                if (i >= len || j >= curr || s[j] > s[i]) continue;
                else start = curr;
                continue;
            }
            i++;
        }
        return s.substr(start);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
