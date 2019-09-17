//
//  main.cpp
//  227.Basic Calculator II
//
//  Created by stevenxu on 9/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;;

class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        stack<int> record;
        int tmp = 0;
        char sign = '+';
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (isdigit(s[i])) {
                tmp = tmp * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == len - 1) {
                if (sign == '+') record.push(tmp);
                else if (sign == '-') record.push(-tmp);
                else {
                    int num = 0;
                    if (sign == '*') num = tmp * record.top();
                    else num = record.top() / tmp;
                    record.pop();
                    record.push(num);
                }
                sign = s[i];
                tmp = 0;
            }
        }
        int res = 0;
        while (!record.empty()) {
            res += record.top();
            record.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
