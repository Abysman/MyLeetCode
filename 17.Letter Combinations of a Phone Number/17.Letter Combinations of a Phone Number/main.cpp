//
//  main.cpp
//  17.Letter Combinations of a Phone Number
//
//  Created by Abysman on 2018/8/1.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        map<string, vector<string>> dict;
        dict["2"] = {"a", "b", "c"};
        dict["3"] = {"d", "e", "f"};
        dict["4"] = {"g", "h", "i"};
        dict["5"] = {"j", "k", "l"};
        dict["6"] = {"m", "n", "o"};
        dict["7"] = {"p", "q", "r", "s"};
        dict["8"] = {"t", "u", "v"};
        dict["9"] = {"w", "x", "y", "z"};
        vector<string> res;
        string s = "";
        sol(digits, res, s, 0, dict);
        return res;
    }
    
    void sol(const string digits, vector<string>& res, string& s, int curr, map<string, vector<string>> dict) {
        if (curr == digits.length()) {
            res.push_back(s);
            return;
        }
        for (int i = 0;i < dict[digits.substr(curr, 1)].size(); ++i) {
            s += dict[digits.substr(curr, 1)][i];
            sol(digits, res, s, curr + 1, dict);
            s.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    map<string, vector<string>> dict;
    string a = "23";
    cout << a.substr(0, 1);
    Solution sol = Solution();
    cout << sol.letterCombinations(a)[0] << "\n";
    return 0;
}
