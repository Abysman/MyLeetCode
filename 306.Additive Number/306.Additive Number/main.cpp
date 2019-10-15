//
//  main.cpp
//  306.Additive Number
//
//  Created by stevenxu on 10/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for (int i = 1; i <= len / 2; ++i) {
            for (int j = 1; j <= (len - i) / 2; ++j) {
                if (helper(num.substr(0, i), num.substr(i, j), num.substr(i + j))) return true;
            }
        }
        return false;
    }
    
    bool helper(string num1, string num2, string num) {
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
        string sum = add(num1, num2);
        if (sum == num) return true;
        if (num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0) return false;
        else return helper(num2, sum, num.substr(sum.size()));
    }
    string add(string num1, string num2) {
        string res;
        int n1 = num1.size() - 1, n2 = num2.size() - 1, carry_out = 0;
        int curr1, curr2;
        
        while (n1 >= 0 || n2 >= 0 || carry_out) {
            curr1 = (n1 < 0 ? 0 : num1[n1] - '0');
            curr2 = (n2 < 0 ? 0 : num2[n2] - '0');
            int sum = carry_out + curr1 + curr2;
            res += (sum % 10 + '0');
            carry_out = sum / 10;
            n1--;
            n2--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
