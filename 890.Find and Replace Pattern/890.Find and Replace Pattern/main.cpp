//
//  main.cpp
//  890.Find and Replace Pattern
//
//  Created by stevenxu on 9/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string formalizedPattern = convert(pattern);
        
        vector<string> res;
        for (string word: words) {
            
            if (convert(word) == formalizedPattern) {
                
                res.push_back(word);
            }
        }
        return res;
    }
    
    string convert(string s) {
        vector<int> tmp(26, -1);
        int count = 0;
        for (char c: s) {
            if (tmp[c - 'a'] == -1) {
                tmp[c - 'a'] = count;
                count++;
            }
        }
        string res = "";
        for (char c: s) {
            res += 'a' + tmp[c - 'a'];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
