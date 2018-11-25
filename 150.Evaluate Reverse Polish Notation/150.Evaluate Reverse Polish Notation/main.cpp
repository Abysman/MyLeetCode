//
//  main.cpp
//  150.Evaluate Reverse Polish Notation
//
//  Created by Abysman on 2018/11/25.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int n1, n2, n3;
        for (auto s:tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                num.push(atoi(s.c_str()));
            }
            else {
                n2 = num.top();
                num.pop();
                n1 = num.top();
                num.pop();
                if (s == "+") n3 = n1 + n2;
                else if (s == "-") n3 = n1 - n2;
                else if (s == "*") n3 = n1 * n2;
                else if (s == "/") n3 = n1 / n2;
                // cout << n1 << " " << n2 << " " << n3 << "\n";
                num.push(n3);
            }
        }
        return num.top();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
