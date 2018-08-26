//
//  main.cpp
//  217.Contains Duplicate
//
//  Created by Abysman on 2018/8/26.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            if (record[nums[i]] == 1) return true;
            record[nums[i]] += 1;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    map<int, int> s;
    s[1] += 1;
    cout << s[1];
    std::cout << "Hello, World!\n";
    return 0;
}
