//
//  main.cpp
//  005.City Connection(Amazon)
//
//  Created by Abysman on 2019/1/30.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;;

class MST{
public:
    struct connection{
        string node1, node2;
        int cost;
    };
    struct node{
        string city;
        map<string, int> adj_cost;
    };
    void make_graph(map<string, node> &graph, vector<connection>::iterator conit, vector<connection>::iterator endit){
        if (conit == endit) return;
        string city1 = conit->node1, city2 = conit->node2;
        int cost = conit->cost;
        graph[city1].city = city1;
        graph[city1].adj_cost[city2] = cost;
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
