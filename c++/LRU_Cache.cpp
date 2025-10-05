#include <bits/stdc++.h>
using namespace std;

/*
  LRU Cache Implementation in C++

  Approach:
  - Use Doubly Linked List + HashMap (unordered_map)
  - Doubly Linked List stores (key, value) nodes in order of usage
  - HashMap maps key -> node for O(1) access
  - Most Recently Used (MRU) = front of list
  - Least Recently Used (LRU) = back of list

  Complexity:
  - get(): O(1)
  - put(): O(1)
*/

class LRUCache {
private:
    int capacity;
    list<pair<int,int>> dll; // stores (key,value)
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1; // not found
        // move accessed node to front (MRU)
        dll.splice(dll.begin(), dll, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        // key exists -> update and move to front
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            dll.splice(dll.begin(), dll, mp[key]);
            return;
        }
        // if cache full -> remove LRU (back)
        if (dll.size() == capacity) {
            int oldKey = dll.back().first;
            dll.pop_back();
            mp.erase(oldKey);
        }
        // insert new key at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

// Example Usage
int main() {
    LRUCache cache(2); // capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl; // 10
    cache.put(3, 30);             // removes key 2
    cout << cache.get(2) << endl; // -1 (not found)
    cache.put(4, 40);             // removes key 1
    cout << cache.get(1) << endl; // -1 (not found)
    cout << cache.get(3) << endl; // 30
    cout << cache.get(4) << endl; // 40

    return 0;
}
