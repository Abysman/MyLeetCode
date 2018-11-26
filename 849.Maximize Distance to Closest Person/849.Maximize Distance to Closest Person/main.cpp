//
//  main.cpp
//  849.Maximize Distance to Closest Person
//
//  Created by Abysman on 2018/11/25.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = INT_MIN;
        int a = 0, b = 0;
        int dis = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 0) b++;
            if (seats[i] == 1) {
                b = i;
                if (seats[a] == 0) res = b - a;
                else {
                    if ((b-a-1) % 2 == 0) dis = (b-a-1) / 2;
                    else dis = (b-a) / 2;
                    res = max(res, dis);
                }
                a = i;
            }
            
        }
        return max(res, b - a);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
