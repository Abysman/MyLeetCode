//
//  main.cpp
//  146.LRU Cache
//
//  Created by stevenxu on 10/28/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class LRUCache {
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> um;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        l.splice(l.begin(), l, um[key]);
        return um[key]->second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            um[key]->second = value;
            return;
        }
        if (um.size() == cap) {
            int delKey = l.back().first;
            l.pop_back();
            um.erase(delKey);
        }
        l.emplace_front(key, value);
        um[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
