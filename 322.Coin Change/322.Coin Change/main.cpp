//
//  main.cpp
//  322.Coin Change
//
//  Created by Abysman on 2019/2/12.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> record(amount + 1, amount + 1);
        record[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto c: coins) {
                if (i >= c) record[i] = min(record[i], record[i - c] + 1);
            }
        }
        return record[amount] > amount ? -1 : record[amount];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
