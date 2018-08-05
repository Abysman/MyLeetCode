//
//  main.cpp
//  205.Isomorphic Strings
//
//  Created by Abysman on 2018/8/5.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> tmp1;
        map<char, int> tmp2;
        for (int i = 0; i < s.length(); ++i) {
            map<char, int>::iterator res1 = tmp1.find(s[i]);
            map<char, int>::iterator res2 = tmp2.find(t[i]);
            if (res1 == tmp1.end() && res2 == tmp2.end()) {
                tmp1.insert(make_pair(s[i], i));
                tmp2.insert(make_pair(t[i], i));
            }
            else if (res1 != tmp1.end() && res2 != tmp2.end()) {
                if (res1->second != res2->second) return false;
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
