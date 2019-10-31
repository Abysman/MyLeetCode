//
//  main.cpp
//  362.Design Hit Counter
//
//  Created by stevenxu on 10/31/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class HitCounter {
private:
    queue<pair<int, int>> record;
    int counts;
    void helper(int timestamp) {
        while (!record.empty() && (timestamp - record.front().first) >= 300) {
            counts -= record.front().second;
            record.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    HitCounter() {
        counts = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        helper(timestamp);
        ++counts;
        if (!record.empty() && timestamp == record.back().first) record.back().second++;
        else record.push({timestamp, 1});
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        helper(timestamp);
        return counts;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
