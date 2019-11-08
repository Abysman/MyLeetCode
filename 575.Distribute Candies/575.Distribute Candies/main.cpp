//
//  main.cpp
//  575.Distribute Candies
//
//  Created by stevenxu on 11/7/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> m;
        for (int candy: candies) m[candy]++;
        return m.size() <= candies.size() / 2 ? m.size() : candies.size() / 2;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
