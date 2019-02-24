//
//  main.cpp
//  75. 寻找峰值
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
    int findPeak(vector<int> &A) {
        int l = 0, r = (int)A.size()-1;
        
        while (l <= r) {
            int mid = (l+r) / 2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
                return mid;
            }
            if (A[mid] < A[mid-1]) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return -1;
    }
    
private:
    
};

/// Tips:
// 二分法，由于A[0]<A[1] A[n-2]<A[n-1]，所以可以保证按二分法一定可以找到一个峰值。所以每次向数值更大的方向继续二分，直到找到峰值。

int main() {
    
    Solution sol = Solution();
    
//    vector<int> v = {1, 2, 1, 3, 4, 5, 7, 6};
    vector<int> v = {1, 2, 3, 4, 1};
    int res = sol.findPeak(v);
    cout << res << endl;
    
    return 0;
}
