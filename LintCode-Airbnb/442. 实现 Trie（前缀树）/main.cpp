//
//  main.cpp
//  442. 实现 Trie（前缀树）
//
//  Created by 边俊林 on 2018/8/18.
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

const int MAXN = 1e5+10;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        tot = 0;
        memset(isWord, 0, sizeof(isWord));
        memset(trie, 0, sizeof(trie));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0;
        for (int i = 0; i < word.length(); ++i) {
            int val = word[i] - 'a';
            if (trie[p][val] == 0) {
                trie[p][val] = ++tot;
            }
            p = trie[p][val];
        }
        isWord[p] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p = 0;
        for (int i = 0; i < word.length(); ++i) {
            int val = word[i] - 'a';
            if (trie[p][val] == 0) return false;
            p = trie[p][val];
        }
        return isWord[p];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int p = 0;
        for (int i = 0; i < prefix.length(); ++i) {
            int val = prefix[i] - 'a';
            if (trie[p][val] == 0) return false;
            p = trie[p][val];
        }
        return true;
    }
private:
    int tot;
    bool isWord[MAXN];
    int trie[MAXN][26];
};


int main(int argc, const char * argv[]) {
    
    Trie obj = *(new Trie());
    obj.insert("apple");
    cout << obj.search("apple") << endl;
    cout << obj.search("app") << endl;
    cout << obj.startsWith("app") << endl;
    obj.insert("app");
    cout << obj.search("app") << endl;
    
    return 0;
}
