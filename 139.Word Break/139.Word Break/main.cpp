//
//  main.cpp
//  139.Word Break
//
//  Created by Abysman on 2018/10/5.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty()) return false;
        vector<bool> record(s.length() + 1, false);
        record[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i - 1; j >= 0; j--) {
                if (record[j]) {
                    string curr = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), curr) != wordDict.end()) {
                        record[i] = true;
                        break;
                    }
                }
            }
        }
        return record[s.length()];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> s = {"1","2","3"};
    if (find(s.begin(), s.end(), "4") == s.end()) {
        cout << "sss";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
