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

//  mine
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count = 0;
        for (int j = n; j > 0; j -= 2) {
            for (int i = 0; i < j - 1; ++i) {
                swap(matrix[count][i + count], matrix[n - 1 - i - count][count]);
                swap(matrix[n - 1 - i - count][count], matrix[n - 1 - count][n - 1 - i - count]);
                swap(matrix[n - 1 - count][n - 1 - i - count], matrix[count + i][n - 1 - count]);
            }
            count += 1;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
