//
//  main.cpp
//  392. 打劫房屋
//
//  Created by 边俊林 on 2018/8/21.
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
     * @param A An array of non-negative integers
     * @return The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        if (A.size() <= 1) return (A.size() == 0) ? 0 : A[0];
        long long *dp = new long long[A.size()];
        memset(dp, 0, A.size() * sizeof(int));
        dp[0] = A[0];
        dp[1] = max(A[0], A[1]);
        for (int i = 2; i < A.size(); ++i) {
            dp[i] = max(dp[i-2]+A[i], dp[i-1]);
        }
        return dp[A.size()-1];
    }
};

int main() {
    
    Solution sol = Solution();
    vector<int> v = {3, 8, 4};
    long long res = sol.houseRobber(v);
    cout << res << endl;
    return 0;
}
