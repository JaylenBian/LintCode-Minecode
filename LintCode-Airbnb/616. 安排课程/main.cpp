//
//  main.cpp
//  616. 安排课程
//
//  Created by 边俊林 on 2018/8/21.
//  Copyright © 2018 minecode. All rights reserved.
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
    /*
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        list<int> *adjs = new list<int>[numCourses];
        int *indegree = new int[numCourses];
        queue<int> q;
        memset(indegree, 0, numCourses * sizeof(int));
        for (int i = 0; i < prerequisites.size(); ++i) {
            auto pir = prerequisites[i];
            int l = pir.first, r = pir.second;
            adjs[l].push_back(r);
            ++indegree[r];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> res;
        int outcnt = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            ++outcnt;
            res.insert(res.begin(), v);
            for (list<int>::iterator it = adjs[v].begin(); it != adjs[v].end(); ++it) {
                if ((--indegree[*it] )== 0) q.push(*it);
            }
        }
        return (outcnt == numCourses) ? res : vector<int>();
    }
};

int main() {
    
    return 0;
}
