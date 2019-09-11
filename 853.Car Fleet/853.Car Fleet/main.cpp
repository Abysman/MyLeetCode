//
//  main.cpp
//  853.Car Fleet
//
//  Created by stevenxu on 9/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> m;
        double time = -1;
        int res = 0;
        for (int i = 0; i < position.size(); ++i) {
            m[-position[i]] = double(target - position[i]) / speed[i];
        }
        for (auto it: m) {
            if (it.second > time) {
                time = it.second;
                res++;
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
