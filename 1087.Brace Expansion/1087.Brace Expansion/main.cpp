//
//  main.cpp
//  1087.Brace Expansion
//
//  Created by stevenxu on 9/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> expand(string S) {
        vector<vector<char>> record;
        vector<string> res;
        int count = 0;
        char last = 'z';
        for (int i = 0; i < S.size(); ++i) {
            count++;
            if (S[i] == '{') {
                vector<char> curr = {};
                while (S[i] != '}') {
                    i++;
                    if (isalpha(S[i])) {
                        curr.push_back(S[i]);
                    }
                }
                sort(curr.begin(), curr.end());
                record.push_back(curr);
            } else if (isalpha(S[i])) {
                vector<char> curr = {S[i]};
                record.push_back(curr);
            }
        }
        string expansion = "";
        helper(record, res, 0, expansion);
        return res;
    }
    
    void helper(vector<vector<char>> record, vector<string> &res, int start, string expansion) {
        if (start == record.size()) {
            res.push_back(expansion);
            return;
        }
        for (int i = 0; i < record[start].size(); ++i) {
            expansion += record[start][i];
            helper(record, res, start + 1, expansion);
            expansion = expansion.substr(0, expansion.size() - 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
