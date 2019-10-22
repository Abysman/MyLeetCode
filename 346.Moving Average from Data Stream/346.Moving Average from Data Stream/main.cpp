//
//  main.cpp
//  346.Moving Average from Data Stream
//
//  Created by stevenxu on 10/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<double> q;
    int N;
    double sum = 0;
    MovingAverage(int size) {
        N = size;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() < N) {
            return sum / q.size();
        } else {
            sum -= q.front();
            q.pop();
            return sum / N;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
