//
//  main.cpp
//  729.My Calendar I
//
//  Created by stevenxu on 12/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class MyCalendar {
    set<pair<int, int>> s;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto f = s.lower_bound(make_pair(start, end));
        if (f != s.end() && f->first < end) return false;
        if (f != s.begin() && (--f)->second > start) return false;
        s.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
