//
//  main.cpp
//  LockAnalyzer_Purestorage
//
//  Created by stevenxu on 9/29/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;;

int checkValid(vector<string> events) {
    int res = 0;
    stack<string> lockStack;
    unordered_set<string> record;
    for (int i = 0; i < events.size(); ++i) {
        string event = events[i];
        string action = event.substr(0, event.find(" "));
        string num = event.substr(event.find(" " ) + 1);
        
        if (action == "ACQUIRE") {
            if (record.find(num) != record.end()) {
                return i + 1;
            }
            record.insert(num);
            lockStack.push(num);
        } else {
            if (lockStack.empty() || lockStack.top() != num) {
                return i + 1;
            }
            lockStack.pop();
            record.erase(num);
        }
    }
    
    if (!lockStack.empty()) {
        return events.size() + 1;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> tests1 = {"ACQUIRE 123", "ACQUIRE 364", "ACQUIRE 84", "RELEASE 84", "RELEASE 364", "ACQUIRE 789", "RELEASE 456", "RELEASE 123"};
    vector<string> tests2 = {"ACQUIRE 364", "ACQUIRE 84", "RELEASE 84", "RELEASE 364"};
    vector<string> tests3 = {"ACQUIRE 364", "ACQUIRE 84", "RELEASE 364", "RELEASE 84"};
    vector<string> tests4 = {"ACQUIRE 364", "ACQUIRE 84", "ACQUIRE 364", "RELEASE 364"};
    cout <<checkValid(tests4);
    return 0;
}
