//
//  main.cpp
//  455.Assign Cookies
//
//  Created by stevenxu on 11/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j = 0;
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i])
                i++;
            j++;
        }
        return i;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
