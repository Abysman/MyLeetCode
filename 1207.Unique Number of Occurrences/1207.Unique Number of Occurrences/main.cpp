//
//  main.cpp
//  1207.Unique Number of Occurrences
//
//  Created by stevenxu on 11/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> record;
        for (int num: arr) record[num]++;
        unordered_set<int> tmp;
        for (auto m: record) {
            if (!tmp.insert(m.second).second) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
