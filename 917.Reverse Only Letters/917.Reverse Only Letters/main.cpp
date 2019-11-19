//
//  main.cpp
//  917.Reverse Only Letters
//
//  Created by stevenxu on 11/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string reverseOnlyLetters(string S) {
        for (int i = 0, j = S.length() - 1; i < j;) {
            if (!isalpha(S[i]))
                ++i;
            else if (!isalpha(S[j]))
                --j;
            else
                swap(S[i++], S[j--]);
        }
        return S;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
