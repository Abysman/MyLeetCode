//
//  main.cpp
//  389.Find the Difference
//
//  Created by Abysman on 2019/1/8.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
//  referenced from https://leetcode.com/problems/find-the-difference/discuss/86826/Concise-C%2B%2B-solution-using-XOR
//class Solution {
//public:
//    char findTheDifference(string s, string t) {
//        char r=0;
//        for(char c:s) r ^=c;
//        for(char c:t) r ^=c;
//        return r;
//    }
//};

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> record(26, 0);
        record[t[0] - 'a'] -= 1;
        for (int i = 0; i < s.size(); ++i) {
            record[s[i] - 'a'] += 1;
            record[t[i + 1] - 'a'] -= 1;
        }
        for (int i = 0; i < record.size(); ++i) {
            if (record[i] < 0) return 'a' + i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
