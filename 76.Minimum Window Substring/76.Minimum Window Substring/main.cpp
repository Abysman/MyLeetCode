//
//  main.cpp
//  76.Minimum Window Substring
//
//  Created by stevenxu on 12/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int n = s.size(), required = t.size();
        unordered_map<char, int> record;
        for (char c: t) record[c]++;
        int end = 0, start = 0, left = 0, min = INT_MAX;
        while (end <= n && start < n) {
            if (required) {
                if (end == n) break;
                record[s[end]]--;
                if (record[s[end]] >= 0) required--;
                end++;
            } else {
                if (end - start < min) {
                    min = end - start;
                    left = start;
                }
                record[s[start]]++;
                if (record[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX ? "" : s.substr(left, min);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
