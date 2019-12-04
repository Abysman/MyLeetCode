//
//  main.cpp
//  267.Palindrome Permutation II
//
//  Created by stevenxu on 12/4/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        int tmp = 0;
        unordered_map<char, int> m;
        string curr = "";
        for (char c: s) {
            m[c] += 1;
            if (m[c] % 2 == 1) tmp += 1;
            else tmp -= 1;
        }
        if (tmp > 1) return res;
        for (auto elem: m) {
            if (elem.second % 2 == 1) {
                curr += elem.first;
                m[elem.first] -= 1;
                break;
            }
        }
        helper(m, res, curr, s.size());
        return res;
    }
    
    void helper(unordered_map<char, int> &m, vector<string> &res, string s, int n) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }
        for (auto elem: m) {
            if (elem.second <= 1) continue;
            char curr = elem.first;
            m[elem.first] -=  2;
            helper(m, res, curr + s + curr, n);
            m[elem.first] += 2;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
