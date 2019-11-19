//
//  main.cpp
//  819.Most Common Word
//
//  Created by stevenxu on 11/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string curr;
        unordered_map<string, int> m;
        unordered_set<string> b(banned.begin(), banned.end());
        for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream in(paragraph);
        while (in >> curr) {
            for (int i = 0; i < curr.size(); ++i) {
                curr[i] = tolower(curr[i]);
            }
            if (b.find(curr) == b.end()) {
                m[curr]++;
            }
        }
        int maxFrequency = 0;
        string res = "";
        for (auto e: m) {
            if (e.second > maxFrequency) {
                maxFrequency = e.second;
                res = e.first;
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
