//
//  main.cpp
//  947.Most Stones Removed with Same Row or Column
//
//  Created by stevenxu on 9/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  union find
class Solution {
public:
    unordered_map<int, int> m;
    int groups = 0;
    int removeStones(vector<vector<int>>& stones) {
        int num = stones.size();
        for (int i = 0; i < num; ++i) {
            uni(stones[i][0], stones[i][1] + 10000);
        }
        return num - groups;
    }
    
    void uni(int a, int b) {
        a = find(a), b= find(b);
        if (a != b) {
            m[a] = b;
            groups--;
        }
    }
    
    int find(int n) {
        if (!m.count(n)) {
            m[n] = n;
            groups++;
        }
        if (m[n] != n) m[n] = find(m[n]);
        return m[n];
    }
};

//  dfs
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int res = 0;
        unordered_map<int, vector<int>> rows, cols;
        unordered_set<int> visitedRows;
        for (auto stone: stones) {
            rows[stone[0]].push_back(stone[1]);
            cols[stone[1]].push_back(stone[0]);
        }
        for (auto row: rows) {
            res += max(0, dfs(rows, cols, visitedRows, row.first) - 1);
        }
        return res;
    }
    
    int dfs(unordered_map<int, vector<int>> rows, unordered_map<int, vector<int>> cols, unordered_set<int>& visitedRows, int row) {
        int curr = 0;
        if (visitedRows.insert(row).second) {
            curr += rows[row].size();
            for (auto c: rows[row]) {
                for (auto r: cols[c]) {
                    curr += dfs(rows, cols, visitedRows, r);
                }
            }
        }
        return curr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
