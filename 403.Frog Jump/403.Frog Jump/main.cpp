//
//  main.cpp
//  403.Frog Jump
//
//  Created by Abysman on 2018/11/7.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    //  BFS
//    bool canCross(vector<int>& stones) {
//        // To record available last steps to reach current position. Position 0 need 0 step to be reached
//        unordered_map<int, unordered_set<int>> steps = {{0, {0}}};
//        
//        for (int pos : stones) {
//            for (auto it = steps[pos].begin(); it != steps[pos].end(); it++) {  // record all future reachable positions
//                if (*it - 1) { steps[pos + *it - 1].insert(*it - 1); }
//                steps[pos + *it].insert(*it);
//                steps[pos + *it + 1].insert(*it + 1);
//            }
//        }
//        
//        return steps[stones.back()].size();                                     // check if the last position is reachable
//    }
    //  DFS
    bool canCross(std::vector<int>& stones, int pos = 0, int k = 0) {
        for (int i = pos + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1) continue;
            if (gap > k + 1) return false;
            if (canCross(stones, i, gap)) return true;
        }
        return pos == stones.size() - 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    std::cout << Solution().test();
    return 0;
}
