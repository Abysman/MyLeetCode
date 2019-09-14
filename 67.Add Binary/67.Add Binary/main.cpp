//
//  main.cpp
//  67.Add Binary
//
//  Created by stevenxu on 9/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        while (i >= 0 || j >= 0 ||  c == 1) {
            c += (i >= 0) ? a[i--] - '0' : 0;
            c += (j >= 0) ? b[j--] - '0' : 0;
            res += char(c % 2 + '0');
            c /= 2;
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
