//
//  main.cpp
//  Round A - 2.Lucky Dip
//
//  Created by 边俊林 on 2019/3/6.
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

/// Tips:
// 期望DP，考虑dp[i]为当剩余放回次数为i时的数学期望最大值。
// 对于i为0，期望即是所有数之和的平均值。对齐其他情况，只有当重新抽的期望大于当前这次时，才会选择重新抽
// 故转移方程为 dp[i] = (largerIdx - 1) / n * dp[i-1] + (sum[n] - sum[largeIdx-1]) / n

const int MAXN = 1e5 + 10;
vector<double> dp = vector<double>(MAXN);
vector<double> sum = vector<double>(MAXN);
vector<double> arr = vector<double>(MAXN);

int main() {
    int T, n, k;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin()+1, arr.begin()+1+n);
        dp[0] = sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + arr[i];
        }
        dp[0] = sum[n] / n;
        for (int i = 1; i <= k; ++i) {
            int largerIdx = (int)(upper_bound(arr.begin()+1, arr.begin()+1+n, dp[i-1]) - arr.begin());
            dp[i] = (double)(largerIdx-1) / n * dp[i-1] + (sum[n] - sum[largerIdx-1]) / n;
        }
        printf("Case #%d: %.6lf\n", kase, dp[k]);
    }

    return 0;
}
