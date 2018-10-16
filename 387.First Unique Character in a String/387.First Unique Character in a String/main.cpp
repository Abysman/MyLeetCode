//
//  main.cpp
//  387.First Unique Character in a String
//
//  Created by Abysman on 2018/10/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

//class Solution {
//public:
//    int firstUniqChar(string s) {
//        unordered_map<char, pair<int, int>> m;
//        int idx = s.size();
//        for (int i = 0; i < s.size(); i++) {
//            m[s[i]].first++;
//            m[s[i]].second = i;
//        }
//        for (auto &p : m) {
//            if (p.second.first == 1) idx = min(idx, p.second.second);
//        }
//        return idx == s.size() ? -1 : idx;
//    }
//};

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> record;
        int res = INT_MAX;
        for (int i = 0; i < s.length(); ++i) {
            record[s[i]] = (record[s[i]] == 0)? i + 1 : -1;
        }
        for (auto iter = record.begin(); iter != record.end(); ++iter) {
            if (iter->second != -1) {
                if (iter->second - 1< res) res = iter->second - 1;
            }
        }
        if (res == INT_MAX) return -1;
        else return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
