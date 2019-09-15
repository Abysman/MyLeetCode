//
//  main.cpp
//  821.Shortest Distance to a Character
//
//  Created by stevenxu on 9/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.size();
        vector<int> res(len, len);
        int position = -len;
        for (int i = 0; i < len; ++i) {
            if (S[i] == C) position = i;
            res[i] = min(res[i], abs(position - i));
        }
        for (int i = len - 1; i >= 0; --i) {
            if (S[i] == C) position = i;
            res[i] = min(res[i], abs(position - i));
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
