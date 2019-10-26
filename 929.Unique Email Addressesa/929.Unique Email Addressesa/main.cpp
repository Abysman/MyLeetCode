//
//  main.cpp
//  929.Unique Email Addressesa
//
//  Created by stevenxu on 10/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> record;
        for (string email: emails) {
            string curr = "";
            bool ignored = false;
            for (int i = 0;i < email.size(); ++i) {
                if (email[i] == '@') {
                    curr += email.substr(i);
                    record.insert(curr);
                    break;
                }
                if (ignored || email[i] == '.') continue;
                else if (email[i] == '+') ignored = true;
                else curr += email[i];
            }
        }
        return record.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
