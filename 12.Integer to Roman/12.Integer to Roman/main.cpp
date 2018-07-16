//
//  main.cpp
//  12.Integer to Roman
//
//  Created by Abysman on 2018/7/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

//public:
//string intToRoman(int num) {
//    string romanPieces[]={"","I","II","III","IV","V","VI","VII","VIII","IX",
//        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
//        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
//        "","M","MM","MMM","MMMM"};
//    return romanPieces[num/1000+30]+romanPieces[(num/100)%10+20]
//    +romanPieces[(num/10)%10+10]+romanPieces[num%10];
//}
//};

class Solution {
public:
    string intToRoman(int num) {
        string result;
        map<int, string> m;
        m.insert(make_pair(1000, "M"));
        m.insert(make_pair(900, "CM"));
        m.insert(make_pair(500, "D"));
        m.insert(make_pair(400, "CD"));
        m.insert(make_pair(100, "C"));
        m.insert(make_pair(90, "XC"));
        m.insert(make_pair(50, "L"));
        m.insert(make_pair(40, "XL"));
        m.insert(make_pair(10, "X"));
        m.insert(make_pair(9, "IX"));
        m.insert(make_pair(5, "V"));
        m.insert(make_pair(4, "IV"));
        m.insert(make_pair(1, "I"));
        int tmp = 0;
        int r = num;
        for (map<int, string>::reverse_iterator iter = m.rbegin();
             iter != m.rend();
             iter++) {
            tmp = r / iter->first;
            r = r % iter->first;
            for(int i = 0;i < tmp; i++) {
                result += iter->second;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s = Solution();
    cout << s.intToRoman(58) << endl;
    return 0;
}
