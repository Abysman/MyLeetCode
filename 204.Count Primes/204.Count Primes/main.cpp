//
//  main.cpp
//  204.Count Primes
//
//  Created by Abysman on 2018/8/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

//int countPrimes(int n) {
//    if (n<=2) return 0;
//    vector<bool> passed(n, false);
//    int sum = 1;
//    int upper = sqrt(n);
//    for (int i=3; i<n; i+=2) {
//        if (!passed[i]) {
//            sum++;
//            //avoid overflow
//            if (i>upper) continue;
//            for (int j=i*i; j<n; j+=i) {
//                passed[j] = true;
//            }
//        }
//    }
//    return sum;
//}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
