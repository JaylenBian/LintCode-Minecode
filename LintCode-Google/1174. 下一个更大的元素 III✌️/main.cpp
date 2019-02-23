//
//  main.cpp
//  1174. 下一个更大的元素 III
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
    int nextGreaterElement(int n) {
        if (n <= 0)
            throw new invalid_argument("n should only be postive");
        
        // Filter elems of n
        vector<int> nums = numberFilter(n);
        
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
            return -1;
        }
        for (int i = pLeft; i < nums.size(); ++i) {
            if (nums[i] == higher) {
                pRight = i;
                break;
            }
        }
        swap(nums[pLeft], nums[pRight]);
        sort(nums.begin()+pLeft+1, nums.end());
        return elemsToNumber(nums);
    }
    
private:
    vector<int> numberFilter(int n) {
        vector<int> nums;
        int tmp = n;
        while (tmp > 0) {
            nums.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
    
    int elemsToNumber(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res *= 10;
            res += nums[i];
        }
        if (res > INT_MAX)
            return -1;
        return (int)res;
    }
    
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
//    int num = 12;
//    int num = 21;
//    int num = 4256;
//    int num = 123851;
    int num = 1999999999;
    int res = sol.nextGreaterElement(num);
    cout << res << endl;
    
    return 0;
}
