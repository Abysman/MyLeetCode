//
//  main.cpp
//  1267.Count Servers that Communicate
//
//  Created by stevenxu on 11/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        vector<int> rows(grid.size(),0),columns(grid[0].size(),0);    //Stores count of servers in rows and colums
        for(int i=0;i<grid.size();i++)                        //Fill the count vectors
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j])
                    rows[i]++,columns[j]++;
        int result=0;
        for(int i=0;i<grid.size();i++)            //Traverse the grid to get result count
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]&&(columns[j]>1||rows[i]>1))    //Check if there are any other server except the current one in it's corresponding row or column.
                    result++;
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
