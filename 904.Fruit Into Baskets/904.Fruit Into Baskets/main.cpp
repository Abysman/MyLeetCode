//
//  main.cpp
//  904.Fruit Into Baskets
//
//  Created by stevenxu on 9/9/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  Sliding window
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int num = tree.size(), left = 0, curr = 0;
        unordered_map<int, int> baskets;
        if (num <= 2) return num;
        while (curr < num) {
            baskets[tree[curr]]++;
            if (baskets.size() > 2) {
                if (--baskets[tree[left]] == 0) baskets.erase(tree[left]);
                left++;
            }
            curr++;
        }
        return curr - left;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
