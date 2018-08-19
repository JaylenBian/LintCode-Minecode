//
//  main.cpp
//  541. 左旋右旋迭代器 II
//
//  Created by 边俊林 on 2018/8/19.
//  Copyright © 2018 minecode. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <cmath>
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

class ZigzagIterator2 {
public:
    /*
     * @param vecs a list of 1d vectors
     */
    ZigzagIterator2(vector<vector<int>>& vecs) {
        int idx = 0;
        int maxx = 0;
        for (auto vec : vecs) {
            maxx = max(maxx, (int)vec.size());
        }
        while (idx < maxx) {
            for (auto vec: vecs) {
                if (idx < vec.size()) {
                    res.push_back(vec[idx]);
                }
            }
            idx++;
        }
        idx = 0;
    }
    
    /*
     * @return An integer
     */
    int next() {
        return res[idx++];
    }
    
    /*
     * @return True if has next
     */
    bool hasNext() {
        return idx < res.size();
    }
private:
    vector<int> res;
    int idx = 0;
};

int main() {
    
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6, 7};
    vector<int> v3 = {8, 9};
    vector<vector<int>> v = {v1, v2, v3};
    
    vector<int> res;
    auto sol = ZigzagIterator2(v);
    while (sol.hasNext()) {
        res.push_back(sol.next());
    }
    for (auto item : res) {
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}
