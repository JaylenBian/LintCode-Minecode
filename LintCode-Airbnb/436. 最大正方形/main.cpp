//
//  main.cpp
//  436. 最大正方形
//
//  Created by 边俊林 on 2018/8/22.
//  Copyright © 2018 minecode. All rights reserved.
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
    /**
     * @param matrix a matrix of 0 and 1
     * @return an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) return 0;
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        int maxx = 0;
        int **dp = new int *[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[m];
            memset(dp[i], 0, m * sizeof(int));
        }
        
        for (int i = 0; i < n; ++i) dp[i][0] = matrix[i][0];
        for (int i = 0; i < m; ++i) dp[0][i] = matrix[0][i];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxx = max(maxx, dp[i][j]);
            }
        }
        return maxx * maxx;
    }
};

int main() {
    
    Solution sol = Solution();
    vector<vector<int>> v = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    int res = sol.maxSquare(v);
    cout << res << endl;
    
    return 0;
}
