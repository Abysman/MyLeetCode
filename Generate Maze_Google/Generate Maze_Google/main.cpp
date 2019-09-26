//
//  main.cpp
//  Generate Maze_Google
//
//  Created by stevenxu on 9/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int getDegree(int x, int y, vector<vector<char>> &maze) {
    int degree = 0;
    if (x > 0 && maze[x-1][y] == ' ') degree++;
    if (y > 0 && maze[x][y-1] == ' ') degree++;
    if (x < maze.size() - 1 && maze[x+1][y] == ' ') degree++;
    if (y < maze[0].size() - 1 && maze[x][y+1] == ' ') degree++;
    return degree;
}

void generateMaze(vector<vector<char>> &maze, int x, int y) {
    vector<vector<int>> dirs = {{0,1},{-1,0},{1,0},{0,-1}};
    random_shuffle(dirs.begin(), dirs.end());

    for (vector<int> dir : dirs) {
        int new_x = x + dir[0];
        int new_y = y + dir[1];

        if (new_x < 0 || new_y < 0 || new_x >= maze.size() || new_y >= maze[0].size() || maze[new_x][new_y] == ' ') continue;
        if (getDegree(new_x, new_y, maze) > 1) continue;
        maze[new_x][new_y] = ' ';
        generateMaze(maze, new_x, new_y);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<char>> test(10, vector<char>(10, '*'));
    generateMaze(test, 0, 0);
    for (auto a : test) {
        for (auto b : a) {
            cout<<b;
        }
        cout<<endl;
    }
    return 0;
}
