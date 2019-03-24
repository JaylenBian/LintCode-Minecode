//
//  main.cpp
//  24. LFU缓存
//
//  Created by 边俊林 on 2019/3/23.
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

#define pipii pair<int, pair<int, int>>
#define pii pair<int, int>

using namespace std;

struct FreqNode {
    int freqCnt;
    FreqNode* prev;
    FreqNode* next;
    struct Node* head;
    struct Node* tail;
    FreqNode(int freqCnt, FreqNode* next)
    : freqCnt(freqCnt), prev(nullptr), next(next), head(nullptr), tail(nullptr)
    { }
};

struct Node {
    int key;
    int val;
    int freqCnt;
    Node* prev;
    Node* next;
    FreqNode* freq;
    Node(int key, int val)
    : key(key), val(val), freqCnt(0), prev(nullptr), next(nullptr), freq(nullptr)
    { }
};

/// Solution:
//
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->hash = unordered_map<int, Node*>();
    }

    void set(int key, int value) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            if (hash.size() == capacity) {
                Node* deletedNode = RemoveNode(this->tail->tail);
                hash.erase(deletedNode->key);
            }
            // Insert New Node
            Node* newNode = new Node(key, value);
            hash[key] = newNode;
            if (this->tail == nullptr) {
                FreqNode* newFreq = new FreqNode(0, nullptr);
                newFreq->tail = newFreq->head = newNode;
                newNode->freq = newFreq;
                this->tail = newFreq;
            } else if (this->tail->freqCnt == 0) {
                FreqNode* tarFreq = this->tail;
                tarFreq->head->next = newNode;
                newNode->prev = tarFreq->head;
                tarFreq->head = newNode;
                newNode->freq = tarFreq;
            } else {
                FreqNode* newFreq = new FreqNode(0, this->tail);
                this->tail->prev = newFreq;
                newFreq->tail = newFreq->head = newNode;
                newNode->freq = newFreq;
                this->tail = newFreq;
            }
        } else {
            it->second->val = value;
            IncreaseNode(it->second);
            return;
        }
    }

    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end())
            return -1;
        IncreaseNode(hash[key]);
        return hash[key]->val;
    }

private:
    int capacity;
    FreqNode* tail = nullptr;
    unordered_map<int, Node*> hash;

    void IncreaseNode(Node* pNode) {
        pNode->freqCnt++;
        bool isSingleNode = pNode->freq->head == pNode->freq->tail;
        if (isSingleNode)
            pNode->freq->freqCnt++;

        if (pNode->freq->next == nullptr) {
            if (!isSingleNode) {
                RemoveNode(pNode);
                FreqNode* newFreq = new FreqNode(pNode->freqCnt, nullptr);
                newFreq->prev = pNode->freq;
                pNode->freq->next = newFreq;
                newFreq->tail = newFreq->head = pNode;
                pNode->freq = newFreq;
            }
        } else if (pNode->freq->next->freqCnt == pNode->freqCnt) {
            RemoveNode(pNode);
            FreqNode* tarFreq = pNode->freq->next;
            pNode->prev = tarFreq->head;
            tarFreq->head->next = pNode;
            tarFreq->head = pNode;
            pNode->freq = tarFreq;
        } else {
            if (!isSingleNode) {
                RemoveNode(pNode);
                FreqNode* newFreq = new FreqNode(pNode->freqCnt, pNode->freq->next);
                pNode->freq->next->prev = newFreq;
                newFreq->prev = pNode->freq;
                pNode->freq->next = newFreq;
                newFreq->tail = newFreq->head = pNode;
                pNode->freq = newFreq;
            }
        }
    }

    Node* RemoveNode(Node* pNode) {
        FreqNode* freq = pNode->freq;
        if (freq->tail == freq->head) {
            RemoveFreqNode(freq);
            return pNode;
        } else {
            if (pNode->prev != nullptr)
                pNode->prev->next = pNode->next;
            if (pNode->next != nullptr)
                pNode->next->prev = pNode->prev;
            if (freq->tail == pNode)
                freq->tail = pNode->next;
            if (freq->head == pNode)
                freq->head = pNode->prev;
            pNode->next = pNode->prev = nullptr;
            return pNode;
        }
    }

    void RemoveFreqNode(FreqNode* pFreqNode) {
        if (pFreqNode->prev != nullptr)
            pFreqNode->prev->next = pFreqNode->next;
        if (pFreqNode->next != nullptr)
            pFreqNode->next->prev = pFreqNode->prev;
        if (this->tail == pFreqNode)
            this->tail = pFreqNode->next;
        delete pFreqNode;
    }
};

/// Tips:
// 为了能在O(1)时间内拿到当前frequency最小的点，同时考虑到frequency有可能存在多个key相同的情况，需要按照添加的顺序来，我们可以设计内外两种Node，外部相同freq合成一个Node，通过链表连接；
// 其内部维护一个链表，保存freq为此值的所有Node，且按照加入顺序排序，由此每次取tail即可获得当前应该删除的值，即频率最低且最早加入。
// 很好的一道题

int main() {

    LFUCache cache = LFUCache(3);
    cache.set(2, 2);
    cache.set(1, 1);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;

    cache.set(3, 3);
    cache.set(4, 4);
    cout << cache.get(3) << endl;
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(4) << endl;

    return 0;
}
