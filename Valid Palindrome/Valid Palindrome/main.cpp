//
//  main.cpp
//  Valid Palindrome
//
//  Created by Abysman on 2018/3/1.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        auto beg = s.begin();
        auto end = --s.end();
        while (end > beg) {
            if (!isalnum(*beg)) {
                ++beg;
                continue;
            }
            
            if (!isalnum(*end)) {
                --end;
                continue;
            }
            
            if (toupper(*beg) == toupper(*end)) {
                ++beg;
                --end;
            }
            else return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    string s = "A man, a plan, a canal: Panama";
    string a = "race a car";
    string c = "0P";
    cout << sol.isPalindrome(c) << endl;
    return 0;
}
