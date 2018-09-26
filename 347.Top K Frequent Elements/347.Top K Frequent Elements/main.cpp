//
//  main.cpp
//  347.Top K Frequent Elements
//
//  Created by Abysman on 2018/9/21.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> map;
        
        for(int num : nums){
            map[num]++;
        }
        
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++){
            pq.push({it->second, it->first});
        }
        for (int i = 0; i < k; ++i) {
            auto p = pq.top();
            res.push_back(p.second);
            pq.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
