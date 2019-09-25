//
//  main.cpp
//  378.Kth Smallest Element in a Sorted Matrix
//
//  Created by stevenxu on 9/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = l + (r - l) / 2;
            int count = 0, j = n - 1;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                count += j + 1;
            }
            // if (count == k) return mid;
            // else if (count > k) r = mid + 1;
            // else l = mid + 1;
            if(count<k)
                l=mid+1;
            else if(count == k) return mid;
            else
                r=mid;
        }
        return l;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> t = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    Solution s = Solution();
    s.kthSmallest(t, 8);
    
    std::cout << "Hello, World!\n";
    return 0;
}
