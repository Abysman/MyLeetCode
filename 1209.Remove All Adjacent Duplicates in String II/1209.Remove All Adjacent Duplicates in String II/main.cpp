//
//  main.cpp
//  1209.Remove All Adjacent Duplicates in String II
//
//  Created by stevenxu on 12/17/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if (n < k) return s;
        int left = 0, right = 0, count = 0;
        for (right = 0; right < n; ++right) {
            if (s[right] == s[left]) {
                count++;
            } else {
                left = right;
                count = 1;
            }
            if (count == k) break;
        }
        if (right == n) return s;
        else return removeDuplicates(s.substr(0, left) + s.substr(right + 1), k);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
