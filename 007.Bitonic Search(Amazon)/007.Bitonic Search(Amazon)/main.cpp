//
//  main.cpp
//  007.Bitonic Search(Amazon)
//
//  Created by Abysman on 2019/2/13.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;;

int solution(vector<int> input, int b) {
    int l = 0, h = input.size() - 1, mid = 0;
    while (l < h) {
        mid = l + (h - l) / 2;
        if (input[mid - 1] > input[mid]) h = mid;
        if (input[mid - 1] < input[mid]) l = mid + 1;
        if (input[mid - 1] < input[mid] && input[mid] > input[mid + 1]) break;
    }
    int splitPoint = mid;
    h = splitPoint, l = 0;
    while (l < h) {
        mid = l + (h - l) / 2;
        if (input[mid] == b) return mid;
        else if (input[mid] < b) l = mid + 1;
        else if (input[mid] > b) h = mid;
    }
    if (input[mid] == b) return mid;
    l = splitPoint, h = input.size() - 1;
    while (l < h) {
        mid = l + (h - l) / 2;
        if (input[mid] == b) return mid;
        else if (input[mid] < b) h = mid;
        else if (input[mid] > b) l = mid + 1;
    }
    if (input[mid] == b) return mid;
    return -1;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3,4,5,6,19,9,8,7};
    cout << solution(a, 9) << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
