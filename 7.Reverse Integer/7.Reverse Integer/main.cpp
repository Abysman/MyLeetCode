//
//  main.cpp
//  7.Reverse Integer
//
//  Created by Abysman on 2018/8/11.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag = (x > 0) ? 1:-1;
        int tmp = x;
        int result = 0;
        while (tmp != 0) {
            if (result > (INT_MAX) / 10) return 0;
            result = result * 10 + tmp % 10;
            if (result * flag < 0) return 0;
            tmp /= 10;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << -123 % 10 << endl;
    return 0;
}
