//
//  main.cpp
//  58.Length of Last Word
//
//  Created by Abysman on 2018/8/1.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int len = 0;
        int start = s.length() - 1;
        while (s[start] == ' ' && start >= 0) {
            start--;
        }
        while (s[start] != ' ' && start >= 0) {
            start--;
            len++;
        }
        return len;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
