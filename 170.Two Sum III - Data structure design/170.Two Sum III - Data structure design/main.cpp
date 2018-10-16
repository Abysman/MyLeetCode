//
//  main.cpp
//  170.Two Sum III - Data structure design
//
//  Created by Abysman on 2018/10/7.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

//class TwoSum {
//    unordered_multiset<int> nums;
//public:
//    void add(int number) {
//        nums.insert(number);
//    }
//    bool find(int value) {
//        for (int i : nums) {
//            int count = i == value - i ? 1 : 0;
//            if (nums.count(value - i) > count) {
//                return true;
//            }
//        }
//        return false;
//    }
//};

class TwoSum {
public:
    /** Initialize your data structure here. */
    map<int, int> record;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        record[number] += 1;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto iter = record.begin(); iter != record.end(); ++iter) {
            auto tmp = record.find(value - iter->first);
            if (tmp != record.end()) {
                if (tmp->first == iter->first && tmp->second == 1) continue;
                return true;
            }
            
        }
        return false;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, World!\n";
    return 0;
}
