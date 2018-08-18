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

// Solution 1: 数组版
/*
class Trie {
public:
    Trie() {
        tot = 0;
        memset(isWord, 0, sizeof(isWord));
        memset(trie, 0, sizeof(trie));
    }
    
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
    
    bool search(string word) {
        int p = 0;
        for (int i = 0; i < word.length(); ++i) {
            int val = word[i] - 'a';
            if (trie[p][val] == 0) return false;
            p = trie[p][val];
        }
        return isWord[p];
    }
    
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
*/

// Solution 2: 指针版
struct TrieNode {
    TrieNode *node[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; ++i) node[i] = NULL;
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            int val = word[i] - 'a';
            if (p->node[val] == NULL) p->node[val] = new TrieNode();
            p = p->node[val];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            int val = word[i] - 'a';
            if (p->node[val] == NULL) return false;
            p = p->node[val];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int val = prefix[i] - 'a';
            if (p->node[val] == NULL) return false;
            p = p->node[val];
        }
        return true;
    }
private:
    TrieNode *root;
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
