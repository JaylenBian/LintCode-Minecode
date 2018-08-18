//
//  main.cpp
//  134. LRU缓存策略
//
//  Created by 边俊林 on 2018/8/18.
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

// Solution:
// Hash + STL

class LRUCache {
public:
    /*
     * @param capacity An integer
     */
    LRUCache(int capacity) :capacity(capacity) { }
    
    /*
     * @param key An integer
     * @return An integer
     */
    int get(int key) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            data.splice(data.begin(), data, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    /*
     * @param key An integer
     * @param value An integer
     * @return nothing
     */
    void set(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            data.splice(data.begin(), data, it->second);
            it->second->second = value;
        } else {
            data.insert(data.begin(), make_pair(key, value));
            hash[key] = data.begin();
            if (data.size() > capacity) {
                hash.erase(data.back().first);
                data.pop_back();
            }
        }
    }
private:
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int capacity;
};

int main() {
    
    LRUCache cache = LRUCache(2);
    cache.set(2, 1);
    cache.set(1, 1);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
    
    return 0;
}
