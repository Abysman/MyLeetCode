//
//  main.cpp
//  225.Implement Stack using Queues
//
//  Created by Abysman on 2018/9/13.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty()) {
                int tmp = q2.front();
                q1.push(tmp);
                q2.pop();
            }
        }
        else {
            q2.push(x);
            while (!q1.empty()) {
                int tmp = q1.front();
                q2.push(tmp);
                q1.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (empty()) return NULL;
        int res;
        if (q1.empty()) {
            res = q2.front();
            q2.pop();
        }
        else {
            res = q1.front();
            q1.pop();
        }
        return res;
    }
    
    
    /** Get the top element. */
    int top() {
        if (empty()) return NULL;
        if (q1.empty()) return q2.front();
        else return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
