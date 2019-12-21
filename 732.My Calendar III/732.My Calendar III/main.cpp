//
//  main.cpp
//  732.My Calendar III
//
//  Created by stevenxu on 12/21/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class MyCalendarThree {
    map<int, int> record;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        record[start]++;
        record[end]--;
        int temp = 0, k = 0;
        for (auto elem: record) {
            temp += elem.second;
            k = max(k, temp);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
