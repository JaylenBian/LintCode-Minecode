//
//  main.cpp
//  5. 第k大元素
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
    int kthLargestElement(int n, vector<int> &nums) {
        if (nums.size() == 0) return -1;
        return Partition(nums, (int)nums.size()-n, 0, (int)nums.size()-1);
    }
    
private:
    int Partition(vector<int>& nums, int n, int begin, int end) {
        int key = nums[end];
        int l = begin, r = end;
        while (l < r) {
            while (l < r && nums[l] <= key) {
                ++l;
            }
            while (l < r && nums[r] >= key) {
                --r;
            }
            swap(nums[l], nums[r]);
        }
        swap(nums[l], nums[end]);
        
        if (l == n) {
            return nums[l];
        } else if (l > n) {
            return Partition(nums, n, begin, l-1);
        } else {
            return Partition(nums, n, l+1, end);
        }
    }
};

/// Tips:
// 基于快排的思想


int main() {
    
    Solution sol = Solution();
//    vector<int> v = {1, 3, 4, 2};
    vector<int> v = {9, 3, 2, 4, 8};
    int res = sol.kthLargestElement(3, v);
    cout << res << endl;
    
    return 0;
}
