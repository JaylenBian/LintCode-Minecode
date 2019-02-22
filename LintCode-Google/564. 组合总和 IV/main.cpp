//
//  main.cpp
//  564. 组合总和 IV
//
//  Created by 边俊林 on 2019/2/21.
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
    int backPackVI(vector<int> &nums, int target) {
        if (nums.size() == 0) return 0;
        int* dp = new int[target+1];
        memset(dp, 0, (target+1) * sizeof(int));
        
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto elem : nums) {
                if (i >= elem)
                    dp[i] += dp[i-elem];
            }
        }
        
        return dp[target];
    }
    
private:
    
};

/// Tips:
// 通过dfs做会超时，可以通过dp来实现


int main() {
    
    Solution sol = Solution();
    vector<int> nums = {1, 2, 4};
    int target = 4;
    int cnt = sol.backPackVI(nums, target);
    cout << cnt << endl;
    
    return 0;
}
