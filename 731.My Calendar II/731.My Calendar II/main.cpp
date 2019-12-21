//
//  main.cpp
//  731.My Calendar II
//
//  Created by stevenxu on 12/21/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class MyCalendarTwo {
    map<int, int> record;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        record[start]++;
        record[end]--;
        int temp = 0;
        for (auto elem: record) {
            temp += elem.second;
            if (temp > 2) {
                record[start]--;
                record[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
