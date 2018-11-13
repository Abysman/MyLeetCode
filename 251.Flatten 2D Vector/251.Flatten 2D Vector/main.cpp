//
//  main.cpp
//  251.Flatten 2D Vector
//
//  Created by Abysman on 2018/11/13.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Vector2D {
public:
    int y = 0;
    vector<vector<int>>::iterator x;
    vector<vector<int>>::iterator End;
    Vector2D(vector<vector<int>>& vec2d) {
        End = vec2d.end();
        x = vec2d.begin();
    }
    
    int next() {
        hasNext();
        return (*x)[y++];
    }
    
    bool hasNext() {
        while (x != End && y == (*x).size()) {
            x++;
            y = 0;
        }
        return x != End;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
