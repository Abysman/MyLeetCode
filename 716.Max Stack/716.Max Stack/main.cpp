//
//  main.cpp
//  716.Max Stack
//
//  Created by Abysman on 2019/2/16.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class MaxStack {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>> m;
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        v.insert(v.begin(), x);
        m[x].push_back(v.begin());
    }
    
    int pop() {
        int x = v.front();
        v.pop_front();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        return x;
    }
    
    int top() {
        return v.front();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int x = m.rbegin()->first;
        auto it = m[x].back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        
        v.erase(it);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
