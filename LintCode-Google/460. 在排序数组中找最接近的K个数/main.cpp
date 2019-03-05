//
//  main.cpp
//  460. 在排序数组中找最接近的K个数
//
//  Created by 边俊林 on 2019/3/5.
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
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        if (A.size() <= 0) return { };

        int idx = findMiddle(A, target);
        int l = idx, r = idx+1;
        int nResSize = min((int)A.size(), k);
        vector<int> res;
        for (int i = 0; i < nResSize; ++i) {
            if (l < 0) {
                res.push_back(A[r++]);
            } else if (r > A.size() - 1) {
                res.push_back(A[l--]);
            } else {
                if (A[l] >= target || target-A[l] <= A[r]-target)
                    res.push_back(A[l--]);
                else
                    res.push_back(A[r++]);
            }
        }
        return res;
    }

private:
    int findMiddle(vector<int>& A, int target) {
        int l = 0, r = (int)A.size()-1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (A[mid] < target) l = mid;
            else r = mid;
        }
        if (A[l] >= target || target-A[l] <= A[r]-target)
            return l;
        return r;
    }
};

/// Tips:
// 主要考察了二分的写法，该问题通过二分查找到最接近target的值，故二分入口为l+1 < r，然后跳出后判断与target关系，熟练使用二分是关键

int main() {

    Solution sol = Solution();
//    vector<int> A = {1, 2, 3};
    vector<int> A = {1, 4, 6, 8};
//    int target = 2;
    int target = 3;
    int k = 3;
    vector<int> res = sol.kClosestNumbers(A, target, k);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
