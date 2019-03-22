//
//  main.cpp
//  437. 书籍复印
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
    int copyBooks(vector<int> &pages, int k) {
        if (k <= 0) return -1;

        vector<vector<int>> dp(k+1, vector<int>(pages.size()+1, 0));
        vector<int> sum(pages.size()+1, 0);
        int maxTime = 0;
        for (int i = 1; i <= pages.size(); ++i) {
            maxTime = max(maxTime, pages[i-1]);
            sum[i] = sum[i-1] + pages[i-1];
        }
        if (k >= pages.size())
            return maxTime;

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= pages.size(); ++j) {
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
        return dp[k][pages.size()];
    }

private:
    const int INF = 0x3f3f3f3f;
};

/// Tips:
// dp题目，dp[i][j]表示i个人复印j个书需要的最短时间，每个人枚举[i, j]区间的m，他人复印[i,m]自己复印[m, j]，通过此转移方程满足依赖关系。

int main() {

    Solution sol = Solution();
    vector<int> pages = {3, 2, 4};
    int k = 2;
    int res = sol.copyBooks(pages, k);
    cout << res << endl;

    return 0;
}
