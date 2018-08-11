//
//  main.cpp
//  125.Valid Palindrome
//
//  Created by Abysman on 2018/8/11.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//bool isPalindrome(string s) {
//    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
//        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
//        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
//        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
//    }
//    
//    return true;
//}

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            while (!((s[i] <= 'Z' && s[i] >= 'A') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
                i++;
                if (i >= j) return true;
            }
            while (!((s[j] <= 'Z' && s[j] >= 'A') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) {
                j--;
                if (j <= i) return true;
            }
            char si = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] + 32) : s[i];
            char sj = (s[j] >= 'A' && s[j] <= 'Z') ? (s[j] + 32) : s[j];
            if (si == sj) {
                i++;
                j--;
                continue;
            }
            else return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
