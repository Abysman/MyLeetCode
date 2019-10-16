//
//  main.cpp
//  315.Count of Smaller Numbers After Self
//
//  Created by stevenxu on 10/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    #define iterator vector<vector<int>>::iterator
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> hold;
        int n = nums.size();
        for (int i = 0; i < n; ++i) hold.push_back(vector<int> ({nums[i], i}));
        vector<int> res(n, 0);
        sort_count(hold.begin(), hold.end(), res);
        return res;
    }
    
    void sort_count(iterator l, iterator r, vector<int>& count) {
        if (r - l <= 1) return;
        iterator m = l + (r - l) / 2;
        sort_count(l, m, count);
        sort_count(m, r, count);
        for (iterator i = l, j = m; i < m; ++i) {
            while (j < r && (*i)[0] > (*j)[0]) j++;
            count[(*i)[1]] += j - m;
        }
        inplace_merge(l, m, r);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
