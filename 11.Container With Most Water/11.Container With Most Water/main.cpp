//
//  main.cpp
//  11.Container With Most Water
//
//  Created by Abysman on 2018/7/30.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water = 0;
        while (i < j) {
            int minHeight = min(height[i], height[j]);
            water = max(water, (j - i) * minHeight);
            while (height[i] <= minHeight && i < j) i++;
            while (height[j] <= minHeight && i < j) j--;
        }
        return water;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
