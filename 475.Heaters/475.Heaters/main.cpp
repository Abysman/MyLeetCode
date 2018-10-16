//
//  main.cpp
//  475.Heaters
//
//  Created by Abysman on 2018/10/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



//  version 1.1
//class Solution {
//public:
//    int findRadius(vector<int>& houses, vector<int>& heaters) {
//        sort(houses.begin(), houses.end());
//        sort(heaters.begin(), heaters.end());
//        int res = INT_MIN, curr;
//        for (int i = 0; i < houses.size(); ++i) {
//            curr = INT_MAX;
//            auto R = lower_bound(heaters.begin(), heaters.end(), houses[i]);
//            if (R != heaters.end()) {
//                curr = min(curr, *R - houses[i]);
//            }
//            if (R != heaters.begin()) {
//                auto L = R - 1;
//                curr = min(curr, houses[i] - *L);
//            }
//            res = max(res, curr);
//        }
//        return res;
//    }
//};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;
        int currD;
        for (int i = 0; i < houses.size(); ++i) {
            int currP = houses[i];
            currD = INT_MAX;
            auto right = upper_bound(heaters.begin(), heaters.end(), currP);
            if (right != heaters.end()) {
                currD = heaters[right - heaters.begin()] - currP;
            }
            if (right != heaters.begin()) {
                currD = min(currD, currP - heaters[right - 1 - heaters.begin()]);
            }
            ans = max(currD, ans);
        }
        return ans;
    }
};

//  failed the last test case
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> res(houses.size());
        int currD, currHouses;
        for (int i = 0; i < houses.size(); ++i) {
            currD = INT_MIN;
            currHouses = houses[i];
            auto right = lower_bound(heaters.begin(), heaters.end(), currHouses);
            if (right != heaters.end()) {
                
            }
        }
        return 0;
    }

};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3,4,5};
    auto b = upper_bound(a.begin(), a.end(), 0);
    std::cout << b << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
