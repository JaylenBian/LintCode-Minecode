//
//  main.cpp
//  540. 左旋右旋迭代器
//
//  Created by 边俊林 on 2018/8/19.
//  Copyright © 2018 minecode. All rights reserved.
//

#include <map>
#include <set>
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

class ZigzagIterator {
public:
    /*
     * @param v1 A 1d vector
     * @param v2 A 1d vector
     */
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        idx = 0;
        res.clear();
        while (idx<v1.size() || idx<v2.size()) {
            if (idx < v1.size()) {
                res.push_back(v1[idx]);
            }
            if (idx < v2.size()) {
                res.push_back(v2[idx]);
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
    int idx;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */

int main() {
    
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4, 5, 6};
    
    vector<int> res;
    auto sol = ZigzagIterator(v1, v2);
    while (sol.hasNext()) {
        res.push_back(sol.next());
    }
    for (auto item : res) {
        cout << item << endl;
    }
    
    return 0;
}
