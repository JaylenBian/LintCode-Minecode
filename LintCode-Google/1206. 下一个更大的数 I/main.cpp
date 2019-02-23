//
//  main.cpp
//  1206. 下一个更大的数 I
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> lower;
        map<int, int> matched;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!lower.empty() && lower.top() < nums2[i]) {
                matched[lower.top()] = nums2[i];
                lower.pop();
            }
            lower.push(nums2[i]);
        }
        vector<int> res = vector<int>(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            if (matched.find(nums1[i]) != matched.end()) {
                res[i] = matched[nums1[i]];
            } else {
                res[i] = -1;
            }
        }
        return res;
    }
    
private:
    
};

/// Tips:
// 考虑如何遍历能获得nums2中，每个比自己大的元素的位置。比两层for循环效率更高的是，通过一个栈，始终保证栈顶元素比栈底元素小，当有一个更大的元素想要加入栈时，将栈内所有比其小的元素a全部出栈，同时通过哈希表保存这个比a大的数，即第一个比a大的数。从而实现找到下一个更大的数。


int main() {
    
    Solution sol = Solution();
    //    vector<int> nums1 = {4, 1, 2};
    //    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    auto res = sol.nextGreaterElement(nums1, nums2);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ",";
    }
    cout << endl;
    
    return 0;
}
