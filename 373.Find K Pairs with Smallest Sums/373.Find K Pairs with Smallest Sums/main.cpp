//
//  main.cpp
//  373.Find K Pairs with Smallest Sums
//
//  Created by Abysman on 2019/2/16.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        k = min(k, m * n);
        vector<int> indice(m, 0);
        while(k-- > 0){
            int tmp_index = 0;
            long tmp_sum = LONG_MAX;
            for(int i = 0; i < m; i++){
                if(indice[i] < n && tmp_sum >= nums1[i] + nums2[indice[i]]){
                    tmp_index = i;
                    tmp_sum = nums1[i] + nums2[indice[i]];
                }
            }
            res.push_back(make_pair(nums1[tmp_index], nums2[indice[tmp_index]]));
            indice[tmp_index]++;
        }
        return res;
    }
};
//  mine
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = nums1.size(), n = nums2.size();
        if ((nums1.empty() || nums2.empty()) || k == 0) return res;
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.push(make_pair(-1 * (nums1[i] + nums2[j]), make_pair(nums1[i], nums2[j])));
            }
        }
        
        while (!pq.empty() && k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
