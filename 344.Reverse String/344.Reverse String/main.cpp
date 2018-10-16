//
//  main.cpp
//  344.Reverse String
//
//  Created by Abysman on 2018/10/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>

class Solution {
public:
    std::string reverseString(std::string s) {
        if (s.empty()) return "";
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
