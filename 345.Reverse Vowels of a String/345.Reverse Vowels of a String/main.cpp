//
//  main.cpp
//  345.Reverse Vowels of a String
//
//  Created by stevenxu on 10/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string reverseVowels(string s) {
        stack<int> position;
        vector<char> vowels;
        int len = s.size(), last = 0;
        for (int i = 0; i < len; ++i) {
            char curr = tolower(s[i]);
            if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u') {
                position.push(i);
                vowels.push_back(s[i]);
            }
        }
        for (int i = 0; i < vowels.size(); ++i) {
            int pos = position.top();
            position.pop();
            s[pos] = vowels[i];
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
