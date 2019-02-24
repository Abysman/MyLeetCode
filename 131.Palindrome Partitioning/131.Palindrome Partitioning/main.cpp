//
//  main.cpp
//  131.Palindrome Partitioning
//
//  Created by Abysman on 2019/2/23.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> sol;
        vector<vector<string>> res;
        helper(0, s, sol, res);
        return res;
    }
    
    void helper(int start, string s, vector<string>& curr, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                helper(i + 1, s, curr, res);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;end--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
