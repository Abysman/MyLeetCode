//
//  main.cpp
//  557.Reverse Words in a String III
//
//  Created by stevenxu on 10/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        s += ' ';
        int start = 0, end = 0;
        while (end < len) {
            while (end < len && s[end + 1] != ' ') end++;
            int curr = end;
            while (start <= end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            start = curr + 2;
            end = start;
        }
        return s.substr(0, len);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
