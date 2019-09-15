//
//  main.cpp
//  690.Employee Importance
//
//  Created by stevenxu on 9/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

/*
 // Employee info
 class Employee {
 public:
 // It's the unique ID of each node.
 // unique id of this employee
 int id;
 // the importance value of this employee
 int importance;
 // the id of direct subordinates
 vector<int> subordinates;
 };
 */
class Solution {
    unordered_map<int, int> m;
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (int i = 0; i < employees.size(); ++i) {
            m[employees[i]->id] = i;
        }
        return helper(employees, id);
    }
    
    int helper(vector<Employee*> employees, int id) {
        Employee* curr = employees[m[id]];
        int res = curr->importance;
        for (int directSubordinate: curr->subordinates) {
            res += getImportance(employees, directSubordinate);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
