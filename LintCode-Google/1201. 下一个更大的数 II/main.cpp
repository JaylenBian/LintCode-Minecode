//
//  main.cpp
//  1201. 下一个更大的数 II
//
//  Created by 边俊林 on 2019/2/23.
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
    vector<int> nextGreaterElements(vector<int> &nums) {
        if (nums.size() == 0) return {};
        
        stack<int> st;
        vector<int> res = vector<int>(nums.size(), -1);
        for (int i = 0; i < nums.size() * 2; ++i) {
            int num = nums[i % nums.size()];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < nums.size()) st.push(i);
        }
        return res;
    }
    
private:
    
};

/// Tips:
// 由于是环状的，故遍历次数增加一倍。利用栈来存放idx，直接操作idx而不是数字，比对后结果可以直接存进最终结果数组，优化时间消耗。


int main() {
    
    Solution sol = Solution();
    vector<int> nums1 = {1, 2, 1};
    auto res = sol.nextGreaterElements(nums1);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ",";
    }
    cout << endl;
    
    return 0;
}
