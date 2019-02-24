//
//  main.cpp
//  38. 搜索二维矩阵 II
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
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        int nRows = (int)matrix.size();
        if (nRows <= 0) return 0;
        int nCols = (int)matrix[0].size();
        
        int row = nRows-1, col = 0;
        int cnt = 0;
        while (row >= 0 && col < nCols) {
            if (matrix[row][col] == target) {
                ++cnt;
                --row; ++col;
                continue;
            }
            if (matrix[row][col] < target)
                ++col;
            else
                --row;
        }
        return cnt;
    }
    
private:
    
};

/// Tips:
// 基础题，从左下角往右上角遍历即可

int main() {
    
    Solution sol = Solution();
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {2, 4, 7, 8},
        {3, 5, 9, 10}
    };
    int target = 3;
    int res = sol.searchMatrix(matrix, target);
    cout << res << endl;
    
    return 0;
}
