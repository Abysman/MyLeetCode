//
//  main.cpp
//  1312.Minimum Insertion Steps to Make a String Palindrome
//
//  Created by stevenxu on 1/6/20.
//  Copyright © 2020 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> record(n, vector<int>(n, -1));
        return helper(s, 0, n - 1, record);
    }
    
    int helper(string &s, int start, int end, vector<vector<int>> &record) {
        if (start >= end) return 0;
        if (record[start][end] != -1) return record[start][end];
        record[start][end] = s[start] == s[end] ? helper(s, start + 1, end - 1, record)
                                            : 1 + min(helper(s, start + 1, end, record),
                                                     helper(s, start, end - 1, record));
        return record[start][end];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
