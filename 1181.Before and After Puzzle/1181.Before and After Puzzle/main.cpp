//
//  main.cpp
//  1181.Before and After Puzzle
//
//  Created by stevenxu on 11/3/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();
        vector<string> res;
        set<string> s;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                stringstream first(phrases[i]);
                stringstream second(phrases[j]);
                string tmp;
                vector<string> firstString;
                vector<string> secondString;
                
                while (first >> tmp) firstString.push_back(tmp);
                while (second >> tmp) secondString.push_back(tmp);
                
                if (firstString.back() == secondString.front()) {
                    string curr = phrases[i];
                    for (int k = 1; k < secondString.size(); ++k) curr += " " + secondString[k];
                    s.insert(curr);
                }
            }
        }
        for (auto e: s) res.push_back(e);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
