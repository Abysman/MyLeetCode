//
//  main.cpp
//  249.Group Shifted Strings
//
//  Created by stevenxu on 10/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<vector<int>,vector<string>> mp;
        for(string &st: strings)
        {
            vector<int> temp;
            for(int i=1; i<st.size(); i++) temp.push_back((26+st[i]-st[i-1])%26);
            mp[temp].push_back(st);
        }
        vector<vector<string>> ans;
        for(auto &t:mp) ans.push_back(t.second);
        return ans;
    }
};

class Solution {
public:
    int mod(int a, int b) { return (a % b + b) % b; }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        if (strings.empty()) return res;
        unordered_map<string, vector<int>> record;
        for (int i = 0; i < strings.size(); ++i) {
            string curr = "0";
            string s = strings[i];
            for (int j = 1; j < s.size(); ++j) {
                curr += "@" + to_string(mod(s[j] - s[0], 26));
            }
            record[curr].push_back(i);
        }
        for (int i = 0; i < strings.size(); ++i) {
            string curr = "0";
            string s = strings[i];
            for (int j = 1; j < s.size(); ++j) {
                curr += "@" + to_string(mod(s[j] - s[0], 26));
            }
            if (record.find(curr) != record.end()) {
                vector<string> v;
                for (int index: record[curr]) v.push_back(strings[index]);
                record.erase(curr);
                res.push_back(v);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
