//
//  main.cpp
//  401. 排序矩阵中的从小到大第k个数
//
//  Created by 边俊林 on 2019/2/27.
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
struct cmp {
    bool operator() (pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int nRows = (int)matrix.size();
        if (nRows <= 0) return 0;
        int nCols = (int)matrix[0].size();
        if (nCols <= 0) return 0;
        
        vector<vector<bool>> vis = vector<vector<bool>>(nRows, vector<bool>(nCols, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> q;
        
        vis[0][0] = true;
        q.push(make_pair(matrix[0][0], make_pair(0, 0)));
        for (int i = 1; i < k; ++i) {
            auto curr = q.top();
            q.pop();
            
            int row = curr.second.first;
            int col = curr.second.second;
            if (row+1 < nRows && !vis[row+1][col]) {
                q.push(make_pair(matrix[row+1][col], make_pair(row+1, col)));
                vis[row+1][col] = true;
            }
            if (col+1 < nCols && !vis[row][col+1]) {
                q.push(make_pair(matrix[row][col+1], make_pair(row, col+1)));
                vis[row][col+1] = true;
            }
        }
        return q.top().first;
    }
    
private:
    
};

/// Tips:
// 通过一个优先队列(小顶堆)来取出当前最小的元素，并将其右和下的元素放进堆中，可以确保堆顶元素始终是剩余元素中最小的。

int main() {
    
    Solution sol = Solution();
//    vector<vector<int>> matrix = {
//        {1, 5, 7},
//        {3, 7, 8},
//        {4, 8, 9}
//    };
//    int k = 4;
    vector<vector<int>> matrix = {
        {1, 2},
        {3, 4}
    };
    int k = 3;
    int res = sol.kthSmallest(matrix, k);
    cout << res << endl;
    
    return 0;
}
