//
//  main.cpp
//  165.Compare Version Numbers
//
//  Created by stevenxu on 11/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
int compareVersion(string version1, string version2) {
    for(auto& w : version1) if (w == '.') w=' ';
    for(auto& w : version2) if (w == '.') w=' ';
    istringstream s1(version1), s2(version2);
    while(1) {
        int n1,n2;
        if (not(s1 >> n1) ) n1 = 0;
        if (not(s2 >> n2) ) n2 = 0;
        if (not s1 and not s2) return 0;
        if (n1<n2) return -1;
        if (n1>n2) return 1;
    }
}
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
