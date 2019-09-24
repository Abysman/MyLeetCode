//
//  main.cpp
//  855.Exam Room
//
//  Created by stevenxu on 9/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class ExamRoom {
    vector<int> rooms;
    int n;
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if (rooms.empty()) {
            rooms.push_back(0);
            return 0;
        }
        
        int maxDis = max(rooms[0], n - 1 - rooms.back());
        int pos = -1, index = -1;
        
        for (int i = 0; i < rooms.size() - 1; ++i) {
            maxDis = max((rooms[i + 1] - rooms[i]) / 2, maxDis);
        }
        
        if (rooms[0] == maxDis) {
            rooms.insert(rooms.begin(), 0);
            return 0;
        }
        
        for (int i = 0; i < rooms.size() - 1; ++i) {
            if ((rooms[i + 1] - rooms[i]) / 2 == maxDis) {
                rooms.insert(rooms.begin() + i + 1, (rooms[i + 1] + rooms[i]) / 2);
                return rooms[i + 1];
            }
        }
        
        rooms.push_back(n - 1);
        return n - 1;
    }
    
    void leave(int p) {
        for (int i = 0; i < rooms.size(); ++i) {
            if (rooms[i] == p) rooms.erase(rooms.begin() + i);
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

class ExamRoom {
public:
    set<int> seats;
    int n;
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        int res = 0, maxDist = *seats.begin();
        if (seats.size() > 0) {
            auto it = seats.begin();
            int prev = *it;
            it++;
            while (it != seats.end()) {
                int currDist = (*it - prev) / 2;
                if (currDist > maxDist) {
                    maxDist = currDist;
                    res = prev + currDist;
                }
                prev = *it;
                it++;
            }
            if (n - 1 - prev > maxDist) {
                res = n - 1;
            }
        }
        seats.insert(res);
        return res;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
