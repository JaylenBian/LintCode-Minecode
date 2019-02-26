//
//  main.cpp
//  374. 螺旋矩阵
//
//  Created by 边俊林 on 2019/2/26.
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
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int nRows = (int)matrix.size();
        if (nRows <= 0) return {};
        int nCols = (int)matrix[0].size();
        
        int circleCount = (min(nRows, nCols) + 1) / 2;
        vector<int> res;
        for (int i = 0; i < circleCount; ++i) {
            printCircle(matrix, i, nRows, nCols, res);
        }
        return res;
    }
    
private:
    void printCircle(vector<vector<int>>& matrix, int pos, int nRows, int nCols, vector<int>& res) {
        for (int i = pos; i < nCols-pos; ++i) {
            res.push_back(matrix[pos][i]);
        }
        for (int i = pos+1; i < nRows-pos; ++i) {
            res.push_back(matrix[i][nCols-pos-1]);
        }
        if (pos != nRows-pos-1) {
            for (int i = nCols-pos-2; i >= pos; --i) {
                res.push_back(matrix[nRows-pos-1][i]);
            }
        }
        if (pos != nCols-pos-1) {
            for (int i = nRows-pos-2; i > pos; --i) {
                res.push_back(matrix[i][pos]);
            }
        }
    }
};

/// Tips:
// 分治法，转换成打印每个环的子问题。

int main() {
    
    Solution sol = Solution();
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
//    vector<vector<int>> matrix = {
//        {6, 4, 1},
//        {7, 8, 9}
//    };
    auto res = sol.spiralOrder(matrix);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << ",";
    }
    cout << endl;
    
    return 0;
}
