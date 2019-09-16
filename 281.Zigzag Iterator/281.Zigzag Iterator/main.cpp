//
//  main.cpp
//  281.Zigzag Iterator
//
//  Created by stevenxu on 9/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty()) q.push(make_pair(v2.begin(), v2.end()));
    }
    
    int next() {
        auto curr = q.front();
        auto it = curr.first, endIt = curr.second;
        if (it + 1 != endIt) q.push(make_pair(it + 1, endIt));
        q.pop();
        return *it;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
