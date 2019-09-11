//
//  main.cpp
//  364.Nested List Weight Sum II
//
//  Created by stevenxu on 9/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int res = 0;
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) return 0;
        vector<int> record;
        for (auto ni : nestedList) {
            dfs(ni, 0, record);
        }
        int res = 0;
        for (int i = record.size() - 1, level = 1; i >= 0; --i, ++level) {
            res += level * record[i];
        }
        return res;
    }
    
    void dfs(NestedInteger nestedInteger, int depth, vector<int>& record) {
        if (depth + 1 > record.size()) record.resize(depth + 1);
        if (nestedInteger.isInteger()) record[depth] += nestedInteger.getInteger();
        else {
            for (NestedInteger n: nestedInteger.getList()) {
                dfs(n, depth + 1, record);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
