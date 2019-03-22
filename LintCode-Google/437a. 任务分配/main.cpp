//
//  main.cpp
//  437a. 任务分配
//
//  Created by 边俊林 on 2019/3/22.
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
    int TaskAllocation(vector<int>& tasks, int k) {
        if (k <= 0) return -1;
        vector<vector<int>> dp(k+1, vector<int>(tasks.size()+1, 0));
        vector<int> sum(tasks.size()+1, 0);
        int maxTask = 0;
        for (int i = 1; i <= tasks.size(); ++i) {
            maxTask = max(maxTask, tasks[i-1]);
            sum[i] = sum[i-1] + tasks[i-1];
        }
        if (k >= tasks.size())
            return maxTask;

        for (int i = 1; i <= k; ++i) {
            for (int j = i; j <= tasks.size(); ++j) {
                if (i == 1)
                    dp[i][j] = sum[j];
                else {
                    dp[i][j] = INF;
                    for (int m = i; m < j; ++m) {
                        dp[i][j] = min(dp[i][j], max(dp[i-1][m], sum[j] - sum[m]));
                    }
                }
            }
        }
        return dp[k][tasks.size()];
    }

private:
    const int INF = 0x3f3f3f3f;
};

/// Tips:
// 同437.书籍复印

int main() {

    Solution sol = Solution();
    vector<int> tasks = {3, 2, 4};
    int k = 2;
    int res = sol.TaskAllocation(tasks, k);
    cout << res << endl;

    return 0;
}
