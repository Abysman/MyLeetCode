//
//  main.cpp
//  605.Can Place Flowers
//
//  Created by stevenxu on 9/10/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (flowerbed[i] + flowerbed[i - 1] + flowerbed[i + 1] == 0) {
                n--;
                i++;
            }
        }
        return n <= 0;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
