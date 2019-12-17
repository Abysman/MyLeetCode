//
//  main.cpp
//  1047.Remove All Adjacent Duplicates In String
//
//  Created by stevenxu on 12/17/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string removeDuplicates(string S) {
        int n = S.size();
        int i = 0;
        for (int j = 0; j < n; ++j, ++i) {
            S[i] = S[j];
            if (i > 0 && S[i - 1] == S[i]) i -= 2;
        }
        return S.substr(0, i);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
