//
//  main.cpp
//  1295.Find Numbers with Even Number of Digits
//
//  Created by stevenxu on 12/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
private:
    bool helper(int num) {
        int count = 0;
        while (num) {
            count += 1;
            num /= 10;
        }
        return count % 2 == 0;
    }
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int num: nums) {
            if (helper(num)) res++;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
