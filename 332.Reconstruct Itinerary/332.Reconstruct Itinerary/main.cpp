//
//  main.cpp
//  332.Reconstruct Itinerary
//
//  Created by stevenxu on 11/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
private:
    unordered_map<string, multiset<string>> dest;
    vector<string> res;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket: tickets) {
            dest[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        return vector<string>(res.rbegin(), res.rend());
    }
    
    void dfs(string loc) {
        while (dest[loc].size() > 0) {
            string next = *dest[loc].begin();
            dest[loc].erase(dest[loc].begin());
            dfs(next);
        }
        res.push_back(loc);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
