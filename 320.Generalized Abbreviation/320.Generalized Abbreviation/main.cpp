//
//  main.cpp
//  320.Generalized Abbreviation
//
//  Created by Abysman on 2019/1/3.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        generateAbbreviationsHelper(word, "", 0, result, false);
        return result;
    }
    
    void generateAbbreviationsHelper(string& word, string abbr, int i, vector<string>& result, bool prevNum) {
        if (i == word.length()) {
            result.push_back(abbr);
            return;
        }
        
        generateAbbreviationsHelper(word, abbr+word[i], i+1, result, false);
        if (!prevNum) {
            // Add number abbreviations only when we added a character instead of an abbreviation earlier
            for (int len = 1; i+len <= word.length(); ++len) {
                generateAbbreviationsHelper(word, abbr+to_string(len), i+len, result, true);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
