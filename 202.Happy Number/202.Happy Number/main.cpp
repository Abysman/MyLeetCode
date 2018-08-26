//
//  main.cpp
//  202.Happy Number
//
//  Created by Abysman on 2018/8/26.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

//int digitSquareSum(int n) {
//    int sum = 0, tmp;
//    while (n) {
//        tmp = n % 10;
//        sum += tmp * tmp;
//        n /= 10;
//    }
//    return sum;
//}
//
//bool isHappy(int n) {
//    int slow, fast;
//    slow = fast = n;
//    do {
//        slow = digitSquareSum(slow);
//        fast = digitSquareSum(fast);
//        fast = digitSquareSum(fast);
//    } while(slow != fast);
//    if (slow == 1) return 1;
//    else return 0;
//}

class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            int t = 0;
            while (n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
        }
        return n == 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
