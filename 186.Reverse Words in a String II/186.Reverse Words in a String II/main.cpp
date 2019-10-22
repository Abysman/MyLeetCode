//
//  main.cpp
//  186.Reverse Words in a String II
//
//  Created by stevenxu on 10/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        for (int i = 0, j = 0; i < s.size(); i = j + 1) {
            for (j = i; j < s.size() && !isblank(s[j]); ++j);
            reverse(s.begin()+i, s.begin()+j);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
