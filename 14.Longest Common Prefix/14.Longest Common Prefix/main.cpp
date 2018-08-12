//
//  main.cpp
//  14.Longest Common Prefix
//
//  Created by Abysman on 2018/8/12.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string prefix = "";
//        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
//            for(int i=0; i<strs.size(); i++)
//                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
//                    return prefix;
//        return prefix;
//    }
//};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        string res;
        int j = 0;
        while (true) {
            for (int i = 0; i < strs.size(); ++i) {
                if (j == strs[i].length()) {
                    if (i > 0) {
                        res = res.substr(0, res.length() - 1);
                    }
                    return res;
                }
                if (i == 0) {
                    res += strs[i][j];
                }
                else if (res[j] != strs[i][j]) {
                    res = res.substr(0, res.length() - 1);
                    return res;
                }
            }
            j++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
