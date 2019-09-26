//
//  main.cpp
//  359.Logger Rate Limiter
//
//  Created by stevenxu on 9/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Logger {
    map<string, int> log;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (log.find(message) == log.end()) {
            log[message] = timestamp;
            return true;
        } else {
            int last = log[message];
            if (timestamp - last >= 10) {
                log[message] = timestamp;
                return true;
            } else return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
