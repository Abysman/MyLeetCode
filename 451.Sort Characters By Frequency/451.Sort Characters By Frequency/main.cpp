//
//  main.cpp
//  451.Sort Characters By Frequency
//
//  Created by stevenxu on 11/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string frequencySort(string s) {
        if (s.size() <= 1) return s;
        string res = "";
        unordered_map<char, int> tmp;
        for (char c: s) tmp[c]++;
        map<int, string> tmp2;
        for (auto elem: tmp) tmp2[elem.second] += string(elem.second, elem.first);
        for (auto iter = tmp2.rbegin(); iter != tmp2.rend(); ++iter) {
            res += iter->second;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
