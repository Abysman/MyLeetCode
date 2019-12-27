//
//  main.cpp
//  271.Encode and Decode Strings
//
//  Created by stevenxu on 12/27/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (string str: strs) {
            int n = str.size();
            res += to_string(n) + "@" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> r;
        int head = 0;
        while (head < s.size()) {
            int f = s.find('@', head);
            int len = stoi(s.substr(head, f - head));
            head = f + 1;
            r.push_back(s.substr(head, len));
            head += len;
        }
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
