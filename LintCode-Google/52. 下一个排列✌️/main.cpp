//
//  main.cpp
//  52. 下一个排列
//
//  Created by 边俊林 on 2019/2/24.
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
    vector<int> nextPermutation(vector<int> &nums) {
        if (nums.size() <= 0) return {};
        int pLeft, pRight, higher;
        pLeft = pRight = higher = -1;
        // Replace the number to be replace
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            if (pLeft == -1 && findHigher(nums, i, higher)) {
                pLeft = i;
                break;
            }
        }
        if (pLeft == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        for (int i = pLeft; i < nums.size(); ++i) {
            if (nums[i] == higher) {
                pRight = i;
                break;
            }
        }
        swap(nums[pLeft], nums[pRight]);
        sort(nums.begin()+pLeft+1, nums.end());
        return nums;
    }
    
private:
    bool findHigher(vector<int>& nums, int begin, int &higher) {
        bool found = false;
        int tmpHigher = INT_MAX;
        for (int i = begin+1; i < nums.size(); ++i) {
            if (nums[i] > nums[begin] && nums[i] < tmpHigher) {
                tmpHigher = nums[i];
                found = true;
            }
        }
        if (found) {
            higher = tmpHigher;
            return true;
        }
        return false;
    }
};

/// Tips:
// 思路就是从右向左，找到一个在其右存在比其更大值的数。如42563中的5，其右侧存在比它大的数。然后交换两个数，并把后面的按升序排列
// 即 42563 -> find(5) -> swap(5, 6) -> 42653 -> sort(3, 4) -> 42635

int main() {
    
    Solution sol = Solution();
//    vector<int> v = {4, 3, 2, 1};
    vector<int> v = {1, 3, 2, 3};
    auto res = sol.nextPermutation(v);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << ",";
    }
    cout << endl;
    
    return 0;
}
