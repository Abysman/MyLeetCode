//
//  main.cpp
//  32.Longest Valid Parentheses
//
//  Created by stevenxu on 11/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> record(n);
        int open = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')' && open > 0) {
                record[i] = record[i - 1] + 2;
                if (i - record[i] > 0) record[i] += record[i - record[i]];
                open--;
            }
            res = max(res, record[i]);
        }
        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
