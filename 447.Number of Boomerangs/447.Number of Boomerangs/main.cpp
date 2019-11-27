//
//  main.cpp
//  447.Number of Boomerangs
//
//  Created by stevenxu on 11/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int out=0;
        for (int i=0; i<points.size(); i++) {
            unordered_map<int,int> map;
            for (int j=0; j<points.size(); j++) {
                int xdist = points[i][0]-points[j][0];
                int ydist = points[i][1]-points[j][1];
                out+=(map[(xdist*xdist+ydist*ydist)]++)*2;
            }
        }
        return out;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
