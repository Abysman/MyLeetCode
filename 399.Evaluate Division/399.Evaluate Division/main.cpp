//
//  main.cpp
//  399.Evaluate Division
//
//  Created by Abysman on 2019/1/2.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//  union find
//  referenced from https://leetcode.com/problems/evaluate-division/discuss/88170/0ms-C%2B%2B-Union-Find-Solution-EASY-to-UNDERSTAND
//class Solution {
//    // date: 2016-09-12     location: Santa Clara City Library
//public:
//    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
//        unordered_map<string, Node*> map;
//        vector<double> res;
//        for (int i = 0; i < equations.size(); i ++) {
//            string s1 = equations[i].first, s2 = equations[i].second;
//            if (map.count(s1) == 0 && map.count(s2) == 0) {
//                map[s1] = new Node();
//                map[s2] = new Node();
//                map[s1] -> value = values[i];
//                map[s2] -> value = 1;
//                map[s1] -> parent = map[s2];
//            } else if (map.count(s1) == 0) {
//                map[s1] = new Node();
//                map[s1] -> value = map[s2] -> value * values[i];
//                map[s1] -> parent = map[s2];
//            } else if (map.count(s2) == 0) {
//                map[s2] = new Node();
//                map[s2] -> value = map[s1] -> value / values[i];
//                map[s2] -> parent = map[s1];
//            } else {
//                unionNodes(map[s1], map[s2], values[i], map);
//            }
//        }
//
//        for (auto query : queries) {
//            if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
//                res.push_back(-1);
//            else
//                res.push_back(map[query.first] -> value / map[query.second] -> value);
//        }
//        return res;
//    }
//
//private:
//    struct Node {
//        Node* parent;
//        double value = 0.0;
//        Node()  {parent = this;}
//    };
//
//    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
//        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
//        double ratio = node2 -> value * num / node1 -> value;
//        for (auto it = map.begin(); it != map.end(); it ++)
//            if (findParent(it -> second) == parent1)
//                it -> second -> value *= ratio;
//        parent1 -> parent = parent2;
//    }
//
//    Node* findParent(Node* node) {
//        if (node -> parent == node)
//            return node;
//        node -> parent = findParent(node -> parent);
//        return node -> parent;
//    }
//};

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<pair<string, double>>> record;
        unordered_set<string> visited;
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            record[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
            record[equations[i].second].push_back(make_pair(equations[i].first, 1.0 / values[i]));
        }
        
        for (auto query:queries) {
            visited.clear();
            double curr = helper(record, visited, query.first, query.second);
            res.push_back(curr);
        }
        return res;
    }
    
    double helper(unordered_map<string, vector<pair<string, double>>> record,
                  unordered_set<string>& visited, string start, string target) {
        if (visited.count(target) > 0 || record.count(start) == 0||
            record.count(target) == 0) return -1;
        if (start == target) return 1.0;
        visited.insert(start);
        for (auto v:record[start]) {
            string neighbr = v.first;
            if (neighbr == target) return v.second;
            if (visited.count(neighbr) == 0) {
                double curr = helper(record, visited, neighbr, target);
                if (curr == -1) continue;
                else {
                    return v.second * curr;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
