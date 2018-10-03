//
//  main.cpp
//  681.Next Closest Time
//
//  Created by Abysman on 2018/10/2.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string nextClosestTime(string time) {
        int minutes[4] = {600, 60, 10, 1};
        int sign = time.find(':');
        string res = "0000";
        int curr = stoi(time.substr(0, sign)) * 60 + stoi(time.substr(sign + 1));
        for (int i = 1, j = 0; i <= 1440; ++i) {
            int tmp = (curr + i) % 1440;
            for (j = 0; j < 4; j++) {
                res[j] = tmp / minutes[j] + '0';
                tmp = tmp % minutes[j];
                if (time.find(res[j]) == string::npos) break;
            }
            if (j == 4) return res.substr(0, 2) + ":" + res.substr(2, 2);
        }
        return res.substr(0, 2) + ":" + res.substr(2, 2);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
