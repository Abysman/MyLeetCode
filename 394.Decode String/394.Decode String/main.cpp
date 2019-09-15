//
//  main.cpp
//  394.Decode String
//
//  Created by stevenxu on 9/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;;
class Solution {
public:
    string decodeString(string s) {
        int position = 0;
        return helper(s, position);
    }
    
    string helper(string s, int& position) {
        string res = "";
        int len = s.size();
        string tmp;
        int repeated = 0;
        for (; position < len; ++position) {
            char curr = s[position];
            if (isdigit(curr)) {
                repeated = repeated * 10 + (curr - '0');
            } else if (curr == '[') {
                tmp = helper(s, ++position);
                for (; repeated > 0; --repeated) res += tmp;
            } else if (curr == ']') {
                return res;
            } else {
                res += curr;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    s.decodeString("3[a]2[bc]");
    return 0;
}
