//
//  main.cpp
//  13.Roman to Integer
//
//  Created by Abysman on 2018/7/15.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

using namespace std;

//int romanToInt(string s)
//{
//    unordered_map<char, int> T = { { 'I' , 1 },
//        { 'V' , 5 },
//        { 'X' , 10 },
//        { 'L' , 50 },
//        { 'C' , 100 },
//        { 'D' , 500 },
//        { 'M' , 1000 } };
//
//    int sum = T[s.back()];
//    for (int i = s.length() - 2; i >= 0; --i)
//    {
//        if (T[s[i]] < T[s[i + 1]])
//        {
//            sum -= T[s[i]];
//        }
//        else
//        {
//            sum += T[s[i]];
//        }
//    }
//
//    return sum;
//}

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int tmp = 0;
        for (auto l:s) {
            switch (l) {
                case 'I':
                    tmp = 2;
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    if (tmp == 2) {
                        result -= tmp;
                    }
                    tmp = 0;
                    break;
                case 'X':
                    result += 10;
                    if (tmp == 2) {
                        result -= tmp;
                    }
                    tmp = 20;
                    break;
                case 'L':
                    result += 50;
                    if (tmp == 20) {
                        result -= tmp;
                    }
                    tmp = 0;
                    break;
                case 'C':
                    result += 100;
                    if (tmp == 20) {
                        result -= tmp;
                    }
                    tmp = 200;
                    break;
                case 'D':
                    result += 500;
                    if (tmp == 200) {
                        result -= tmp;
                    }
                    tmp = 0;
                    break;
                case 'M':
                    result += 1000;
                    if (tmp == 200) {
                        result -= tmp;
                    }
                    tmp = 0;
                    break;
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
