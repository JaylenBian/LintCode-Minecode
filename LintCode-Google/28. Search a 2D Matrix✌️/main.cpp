//
//  main.cpp
//  28. Search a 2D Matrix
//
//  Created by 边俊林 on 2019/2/24.
//  Copyright © 2019 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int nRows = (int)matrix.size();
        if (nRows <= 0) return false;
        int nCols = (int)matrix[0].size();
        
        int row = nRows-1, col = 0;
        while (row >= 0 && col < nCols) {
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] < target)
                ++col;
            else
                --row;
        }
        return false;
    }
    
private:
    
};

/// Tips:
// 不难

int main() {
    
    Solution sol = Solution();
    vector<vector<int>> v = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target = 3;
    bool res = sol.searchMatrix(v, target);
    cout << (res ? "true" : "false") << endl;
    
    return 0;
}
