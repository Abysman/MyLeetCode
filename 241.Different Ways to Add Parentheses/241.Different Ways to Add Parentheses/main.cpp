//
//  main.cpp
//  241.Different Ways to Add Parentheses
//
//  Created by stevenxu on 11/1/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    unordered_map<string, vector<int>> m;
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int len = input.size();
        for (int i = 0; i < len; ++i) {
            if (isdigit(input[i])) continue;
            vector<int> first, second;
            string firstString = input.substr(0, i), secondString = input.substr(i + 1);
            if (m.find(firstString) != m.end()) {
                first = m[firstString];
            } else {
                first = diffWaysToCompute(firstString);
                m[firstString] = first;
            }
            if (m.find(secondString) != m.end()) {
                second = m[secondString];
            } else {
                second = diffWaysToCompute(secondString);
                m[secondString] = second;
            }
            for (int n1: first) {
                for (int n2: second) {
                    if (input[i] == '+') res.push_back(n1 + n2);
                    else if (input[i] == '-') res.push_back(n1 - n2);
                    else if (input[i] == '*') res.push_back(n1 * n2);
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
