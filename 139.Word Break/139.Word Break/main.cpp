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
        unordered_set<string> record;
        
        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (string word: wordDict) record.insert(word);
        
        for (int i = 1; i <= len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string curr = s.substr(j, i - j);
                    if (record.find(curr) != record.end()) {
                        dp[i] = true;
                        break;
                    }
                }
                
            }
            
        }
        return dp[len];
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
