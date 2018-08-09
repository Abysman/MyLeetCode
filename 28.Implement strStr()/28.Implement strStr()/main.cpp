//
//  main.cpp
//  28.Implement strStr()
//
//  Created by Abysman on 2018/8/8.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        if (needle.empty()) return index;
        if (haystack.length() < needle.length()) return -1;
        int i = 0, j = 0;
        while (i <= haystack.length() - needle.length()) {
            index = i;
            while (haystack[i] == needle[j] && j < needle.length()) {
                i++;
                j++;
            }
            if (j != needle.length()) {
                j = 0;
                index = -1;
                i++;
            }
            else {
                break;
            }
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    string a = "mississippi";
    string b = "issip";
    cout << sol.strStr(a, b);
    std::cout << "Hello, World!\n";
    return 0;
}
