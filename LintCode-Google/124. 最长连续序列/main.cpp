//
//  main.cpp
//  124. 最长连续序列
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
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0) return 0;
        
        unordered_set<int> existed(num.begin(), num.end());
        
        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (existed.find(num[i]) != existed.end()) {
                existed.erase(num[i]);
                int preNum = num[i] - 1;
                int nxtNum = num[i] + 1;
                while (existed.find(preNum) != existed.end()) {
                    existed.erase(preNum--);
                }
                while (existed.find(nxtNum) != existed.end()) {
                    existed.erase(nxtNum++);
                }
                res = max(res, nxtNum-preNum-1);
            }
        }
        return res;
    }
    
private:
    
};

/// Tips:
// 通过哈希表来实现O(1)时间内的增删。
// 有一个优化点：当找到一个值后，向其前后遍历，找到整个升序队列，然后erase他们。

int main() {
    
    Solution sol = Solution();
//    vector<int> nums = {100, 4, 200, 1, 3, 2};
    vector<int> nums = {100, 4, 200, 101, 102, 1, 3, 2};
    int res = sol.longestConsecutive(nums);
    cout << res << endl;
    
    return 0;
}
