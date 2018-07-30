//
//  main.cpp
//  66.Plus One
//
//  Created by Abysman on 2018/7/30.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry_out = 1;
        int temp = 0;
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it) {
            temp = *it + carry_out;
            carry_out = temp / 10;
            int next = temp % 10;
            *it = next;
        }
        if (carry_out > 0) {
            digits.insert(digits.begin(), carry_out);
        }
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
