//
//  main.cpp
//  482.License Key Formatting
//
//  Created by stevenxu on 10/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n = S.size(), curr = 0;
        string res = "";
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] != '-') {
                if (curr != 0 && curr % K == 0) {
                    res += '-';
                    curr = 0;
                }
                res += toupper(S[i]);
                curr++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
