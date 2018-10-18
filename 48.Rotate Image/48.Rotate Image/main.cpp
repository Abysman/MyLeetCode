//
//  main.cpp
//  48.Rotate Image
//
//  Created by Abysman on 2018/10/17.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int a = 0;
    int b = n-1;
    while(a<b){
        for(int i=0;i<(b-a);++i){
            swap(matrix[a][a+i], matrix[a+i][b]);
            swap(matrix[a][a+i], matrix[b][b-i]);
            swap(matrix[a][a+i], matrix[b-i][a]);
        }
        ++a;
        --b;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
