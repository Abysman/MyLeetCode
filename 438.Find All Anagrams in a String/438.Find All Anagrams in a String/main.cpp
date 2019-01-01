//
//  main.cpp
//  438.Find All Anagrams in a String
//
//  Created by Abysman on 2018/12/31.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> record(26, 0), curr(26, 0), res;
        if (s.size() < p.size()) return res;
        for (int i = 0; i < p.size(); ++i) {
            record[p[i] - 'a']++;
            curr[s[i] - 'a']++;
        }
        
        if (curr == record) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            curr[s[i] - 'a']++;
            curr[s[i - p.size()] - 'a']--;
            if (curr == record) {
                res.push_back(i - p.size() + 1);
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
