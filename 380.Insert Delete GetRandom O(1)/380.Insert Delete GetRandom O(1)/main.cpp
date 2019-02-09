//
//  main.cpp
//  380.Insert Delete GetRandom O(1)
//
//  Created by Abysman on 2019/2/9.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (record.find(val) != record.end()) return false;
        nums.emplace_back(val);
        record[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (record.find(val) == record.end()) return false;
        int b = nums.back();
        record[b] = record[val];
        nums[record[val]] = b;
        nums.pop_back();
        record.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> record;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
