//
//  main.cpp
//  318.Maximum Product of Word Lengths
//
//  Created by Abysman on 2018/9/15.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end());
        int res = 0;
        vector<int> a(26, 0);
        vector<vector<int>> tmp(words.size(), a);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                tmp[i][words[i][j] - 'a'] = 1;
            }
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                int k = 0;
                while (k < 26) {
                    if (tmp[i][k] == 1) {
                        if (tmp[i][k] == tmp[j][k]) {
                            break;
                        }
                    }
                    k++;
                }
                if (k == 26) {
                    cout << words[i] << " " << words[j] << "\n";
                    res = words[i].length() * words[j].length() > res ? words[i].length() * words[j].length() : res;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> s = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution a = Solution();
    cout << a.maxProduct(s);
}
