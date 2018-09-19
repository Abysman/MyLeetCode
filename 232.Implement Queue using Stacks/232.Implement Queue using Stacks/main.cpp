//
//  main.cpp
//  232.Implement Queue using Stacks
//
//  Created by Abysman on 2018/9/19.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) {
            while (!s2.empty()) {
                int tmp = s2.top();
                s1.push(tmp);
                s2.pop();
            }
            s1.push(x);
            while (!s1.empty()) {
                int tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
        }
        else {
            while (!s1.empty()) {
                int tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
            s2.push(x);
            while (!s2.empty()) {
                int tmp = s2.top();
                s1.push(tmp);
                s2.pop();
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (empty()) {
            return NULL;
        }
        int res = peek();
        if (s1.empty()) {
            s2.pop();
        }
        else if (s2.empty()) {
            s1.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (empty()) return NULL;
        if (s1.empty()) return s2.top();
        if (s2.empty()) return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
