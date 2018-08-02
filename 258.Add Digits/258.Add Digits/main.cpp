//
//  main.cpp
//  258.Add Digits
//
//  Created by Abysman on 2018/8/2.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        int currNum = num;
        int result = num;
        int add_num = 0;
        while (result >= 10) {
            currNum = result;
            result = 0;
            while (currNum > 0) {
                add_num = currNum % 10;
                currNum /= 10;
                result += add_num;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
