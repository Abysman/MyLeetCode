//
//  main.cpp
//  9.Palindrome Number
//
//  Created by Abysman on 2018/8/7.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};


//  mine
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int tmp = x;
        vector<int> record;
        while (tmp > 0) {
            record.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int i = 0; i < record.size() / 2; ++i) {
            if (record[i] != record[record.size() - 1- i]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
