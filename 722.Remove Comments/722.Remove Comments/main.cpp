//
//  main.cpp
//  722.Remove Comments
//
//  Created by stevenxu on 10/5/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        int n = source.size();
        string res = "";
        bool inBlock = false;
        for (string s: source) {
            int i = 0;
            while (i < s.size()) {
                if (!inBlock) {
                    if (i == s.size() - 1) res += s[i++];
                    else {
                        string tmp = s.substr(i, 2);
                        if (tmp == "/*") {
                            inBlock = true;
                            i += 2;
                        } else if (tmp == "//" ) {
                            break;
                        } else {
                            res += s[i++];
                        }
                    }
                } else {
                    if (i == s.size() - 1) i++;
                    else {
                        string tmp = s.substr(i, 2);
                        if (tmp == "*/") {
                            inBlock = false;
                            i += 2;
                        } else i++;
                    }
                }
            }
            if (!res.empty() && !inBlock) {
                ans.push_back(res);
                res = "";
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
