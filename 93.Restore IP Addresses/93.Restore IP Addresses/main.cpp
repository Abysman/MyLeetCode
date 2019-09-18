//
//  main.cpp
//  93.Restore IP Addresses
//
//  Created by stevenxu on 9/17/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) return vector<string> ();
        vector<string> res;
        helper(s, "", 0, 0, res);
        return res;
    }
    
    void helper(string s, string ip, int part, int start, vector<string>& res) {
        if (start == s.size() && part == 4) {
            ip.erase(ip.size() - 1);
            res.push_back(ip);
            return;
        }
        if (s.size() - start < 4 - part) return;
        if (s.size() - start > (4 - part) * 3) return;
        int num = 0;
        for (int i = start; i < start + 3; ++i) {
            num = num * 10 + s[i] - '0';
            if (num <= 255) {
                ip += s[i];
                helper(s, ip + '.', part + 1, i + 1, res);
            }
            if (num == 0) break;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
