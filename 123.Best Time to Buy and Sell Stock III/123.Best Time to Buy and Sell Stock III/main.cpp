//
//  main.cpp
//  123.Best Time to Buy and Sell Stock III
//
//  Created by stevenxu on 8/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oneBuy = INT_MAX, twoBuy = INT_MAX;
        int oneSell = 0, twoSell = 0;
        for (int price: prices) {
            oneBuy = min(price, oneBuy);
            oneSell = max(oneSell, price - oneBuy);
            twoBuy = min(twoBuy, price - oneSell);
            twoSell = max(twoSell, price - twoBuy);
        }
        return twoSell;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
