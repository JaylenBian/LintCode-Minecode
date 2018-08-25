//
//  main.cpp
//  76. 最长上升子序列
//
//  Created by 边俊林 on 2018/8/25.
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
     * @param nums An integer array
     * @return The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        int n = (int)nums.size();
        int *dp = new int[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int maxx = 0;
        for (int i = 0; i < n; ++i) {
            maxx = max(maxx, dp[i]);
        }
        return maxx;
    }
};

int main() {
    
    Solution sol = Solution();
    vector<int> v = {88,4,24,82,86,1,56,74,71,9,8,18,26,53,77,87,60,27,69,17,76,23,67,14,98,13,10,83,20,43,39,29,92,31,0,30,90,70,37,59};
    int res = sol.longestIncreasingSubsequence(v);
    cout << res << endl;
    
    return 0;
}
