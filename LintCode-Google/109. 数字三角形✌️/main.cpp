//
//  main.cpp
//  109. 数字三角形
//
//  Created by 边俊林 on 2019/2/25.
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
    int minimumTotal(vector<vector<int>> &triangle) {
        int nLayer = (int)triangle.size();
        if (nLayer <= 0) return 0;
        
        int nNumCount = (1+nLayer) * nLayer / 2;
        int* dp = new int[nNumCount];
        memset(dp, 0, nNumCount * sizeof(int));
        
        dp[0] = triangle[0][0];
        for (int i = 1; i < nLayer; ++i) {
            for (int j = 0; j < i+1; ++j) {
                if (j == 0) {
                    dp[getIndex(i, j)] = dp[getIndex(i-1, j)] + triangle[i][j];
                } else if (j == i) {
                    dp[getIndex(i, j)] = dp[getIndex(i-1, j-1)] + triangle[i][j];
                } else {
                    dp[getIndex(i, j)] = min(dp[getIndex(i-1, j-1)], dp[getIndex(i-1, j)]) + triangle[i][j];
                }
            }
        }
        int maxx = INT_MAX;
        for (int i = 0; i < nLayer; ++i) {
            maxx = min(maxx, dp[getIndex(nLayer-1, i)]);
        }
        return maxx;
    }
    
private:
    int getIndex(int nLayer, int nIdx) {
        return (1+nLayer) * nLayer / 2 + nIdx;
    }
};

/// Tips:
// DP基础题

int main() {
    
    Solution sol = Solution();
//    vector<vector<int>> triangle = {
//        {2},
//        {3, 4},
//        {6, 5, 7},
//        {4, 1, 8, 3}
//    };
    vector<vector<int>> triangle = {
        {2},
        {3, 2},
        {6, 5, 7},
        {4, 4, 8, 1}
    };
    int res = sol.minimumTotal(triangle);
    cout << res << endl;
    
    return 0;
}
