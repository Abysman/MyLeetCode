//
//  main.cpp
//  340.Longest Substring with At Most K Distinct Characters
//
//  Created by Abysman on 2019/2/4.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> m;
        int res = 0, left = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            m[s[i]]++;
            while (m.size() > k) {
                if (--m[s[left]] == 0) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
