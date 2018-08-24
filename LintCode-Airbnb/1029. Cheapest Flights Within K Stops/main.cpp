//
//  main.cpp
//  1029. Cheapest Flights Within K Stops
//
//  Created by 边俊林 on 2018/8/23.
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
// SSSP

const int MAXNUM = 1e8;
class Solution {
public:
    /**
     * @param n a integer
     * @param flights a 2D array
     * @param src a integer
     * @param dst a integer
     * @param K a integer
     * @return return a integer
     */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        int m = (int)flights.size();
        int *dist = new int[n];
        for (int i = 0; i < n; ++i) {
            dist[i] = MAXNUM;
        }
        dist[src] = 0;
        
        for (int i = 0; i <= K; ++i) {
            int *newDist = new int[n];
            memcpy(newDist, dist, n * sizeof(int));
            
            for (int j = 0; j < m; ++j) {
                int u = flights[j][0];
                int v = flights[j][1];
                int w = flights[j][2];
                newDist[v] = min(newDist[v], dist[u] + w);
            }
            dist = newDist;
        }
        
        // detect nagative cycle (no need)
        
        //
        return dist[dst] == MAXNUM ? -1 : dist[dst];
    }
};

int main() {
    
    Solution sol = Solution();
    int n = 3;
    vector<vector<int>> v = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 2, k = 0;
    int res = sol.findCheapestPrice(n, v, src, dst, k);
    
    cout << res << endl;
    
    return 0;
}
