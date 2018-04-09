//
//  main.cpp
//  Valid Parentheses
//
//  Created by Abysman on 2018/4/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string::iterator p1 = s.begin();
        map<char, char> tmp;
        tmp.insert(make_pair(')', '('));
        tmp.insert(make_pair(']', '['));
        tmp.insert(make_pair('}', '{'));
        stack <char>stk;
        while (p1 != s.end()) {
            if ((*p1 == '(') || (*p1 == '[') || (*p1 == '{')) {
                stk.push(*p1);
            }
            else if ((*p1 == ')') || (*p1 == ']') || (*p1 == '}')) {
                if (stk.size() == 0) {
                    return false;
                }
                if (stk.top() == tmp[*p1]) {
                    stk.pop();
                }
                else return false;
            }
            p1++;
        }
        if (stk.size() != 0) {
            return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "()";
    Solution sol = Solution();
    cout << sol.isValid(s) << endl;
    return 0;
}
