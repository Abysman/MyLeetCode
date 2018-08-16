//
//  main.cpp
//  49.Group Anagrams
//
//  Created by Abysman on 2018/8/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> record;
        int i = 0;
        for (auto s:strs) {
            sort(s.begin(), s.end());
            record[s].push_back(strs[i++]);
        }
        
        for (auto m:record) {
            res.push_back(m.second);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<string> a = {"eat","tea","tan","nat"};
//    Solution sol = Solution();
//    vector<vector<string>> res = sol.groupAnagrams(a);
//    for (int i = 0; i < res.size(); ++i) {
//        for (int j = 0; j < res[i].size(); ++j) {
//            cout << res[i][j] << " ";
//        }
//        cout << "\n";
//    }
    return 0;
}
