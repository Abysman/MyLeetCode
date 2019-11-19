//
//  main.cpp
//  157.Read N Characters Given Read4
//
//  Created by stevenxu on 11/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char buf4[4] = {0};
        int times = n/4;
        int index = 0;
        for (int i = 0; i < times; i++) {
            int size = read4(buf4);
            for (int j = 0; j < size; j++)
                buf[index++] = buf4[j];
        }
        int leftOver = n%4;
        if (leftOver != 0) {
            int size = read4(buf4);
            int minSize = min(leftOver, size);
            for (int j = 0; j < minSize; j++)
                buf[index++] = buf4[j];
        }
        return index;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
