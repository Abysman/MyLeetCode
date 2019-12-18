//
//  main.cpp
//  295.Find Median from Data Stream
//
//  Created by stevenxu on 12/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    bool even = true;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (even) {
            large.push(num);
            small.push(large.top());
            large.pop();
        } else {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if (even) {
            return (small.top() + large.top()) * 1.0 / 2;
        } else {
            return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
