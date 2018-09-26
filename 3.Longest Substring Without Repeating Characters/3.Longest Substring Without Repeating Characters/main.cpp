//
//  main.cpp
//  3.Longest Substring Without Repeating Characters
//
//  Created by Abysman on 2018/9/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
//    int lengthOfLongestSubstring(string s) {
//        unordered_map<char, int> tmp;
//        int currLen = 0;
//        int maxLen = 0;
//        int i = 0;
//        int j = 1;
//        while (i <= s.length()) {
//            cout << s[i] << " " << tmp[s[i]] << "\n";
//            if (tmp[s[i]] == 0) {
//                currLen += 1;
//                tmp[s[i]] = j++;
//                i++;
//                if (i == s.length()) {
//                    if (currLen > maxLen) maxLen = currLen;
//                }
//            }
//            else {
//                if (currLen > maxLen) maxLen = currLen;
//                i = i - (currLen - tmp[s[i]]);
//                tmp.clear();
//                currLen = 1;
//                j = 1;
//                tmp[s[i]] = j++;
//                i++;
//            }
//        }
//        return maxLen;
//    }
    
    int lengthOfLongestSubstring(string s) {
        vector<int> d(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (d[s[i]] > start){
                cout << s[i] << d[s[i]] << "\n";
                start = d[s[i]];
            }
            
            d[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    unordered_map<char, int> t;
//    Solution s = Solution();
//    string ss = "abasdasd";
//    cout << s.lengthOfLongestSubstring(ss);
//    std::cout << "Hello, World!\n";
    vector<int> d(256,-1);
    cout << int('a');
    return 0;
}
