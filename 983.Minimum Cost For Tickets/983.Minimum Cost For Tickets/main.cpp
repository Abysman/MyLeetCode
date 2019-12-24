//
//  main.cpp
//  983.Minimum Cost For Tickets
//
//  Created by stevenxu on 12/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366);
        for (int day: days) dp[day] = costs[0];
        for (int i = 1; i <= days[n - 1]; ++i) {
            if (!dp[i]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + costs[0];
                dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
                dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
            }
        }
        return dp[days[n - 1]];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
