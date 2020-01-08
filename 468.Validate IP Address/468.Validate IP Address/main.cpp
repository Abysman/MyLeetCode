//
//  main.cpp
//  468.Validate IP Address
//
//  Created by stevenxu on 1/8/20.
//  Copyright © 2020 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string validIPAddress(string IP) {
        return validIPv4(IP) ? "IPv4" : (validIPv6(IP) ? "IPv6" : "Neither");
    }
    
private:
    bool validIPv4(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3) {
            return false;
        }
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0') {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            if (stoi(part) > 255) {
                return false;
            }
        }
        return true;
    }
    
    bool validIPv6(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 4) {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        return true;
    }
    
    vector<string> split(string s, char c) {
        vector<string> parts;
        string part;
        istringstream in(s);
        while (getline(in, part, c)) {
            parts.push_back(part);
        }
        return parts;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
