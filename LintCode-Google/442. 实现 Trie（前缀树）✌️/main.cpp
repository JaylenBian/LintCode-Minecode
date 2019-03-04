//
//  main.cpp
//  442. 实现 Trie（前缀树）
//
//  Created by 边俊林 on 2019/3/4.
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
struct Node {
    bool isWord;
    vector<Node*> next;
    Node() : isWord(false), next(vector<Node*>(26, nullptr)) { }
};

class Trie {
public:
    Trie() {
        pRoot = new Node();
    }

    void insert(string &word) {
        Node* pNode = pRoot;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word[i] - 'a';
            if (pNode->next[idx] == nullptr)
                pNode->next[idx] = new Node();
            if (i == word.length()-1)
                pNode->next[idx]->isWord = true;
            pNode = pNode->next[idx];
        }
    }

    bool search(string &word) {
        Node* pNode = pRoot;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word[i] - 'a';
            if (pNode->next[idx] == nullptr)
                return false;
            pNode = pNode->next[idx];
        }
        return pNode->isWord;
    }

    bool startsWith(string &prefix) {
        Node* pNode = pRoot;
        for (int i = 0; i < prefix.length(); ++i) {
            int idx = prefix[i] - 'a';
            if (pNode->next[idx] == nullptr)
                return false;
            pNode = pNode->next[idx];
        }
        return true;
    }

private:
    Node* pRoot;
};

/// Tips:
// 注意判断isWord变量，仔细读题

int main() {

    Trie trie = Trie();
    string str;
    str = "lintcode";
    trie.insert(str);

    str = "code";
    cout << (trie.search(str) ? "true" : "false") << endl;

    str = "lint";
    cout << (trie.startsWith(str) ? "true" : "false") << endl;

    str = "linterror";
    cout << (trie.startsWith(str) ? "true" : "false") << endl;

    str = "linterror";
    trie.insert(str);

    str = "lintcode";
    cout << (trie.search(str) ? "true" : "false") << endl;

    str = "linterror";
    cout << (trie.startsWith(str) ? "true" : "false") << endl;

    return 0;
}
