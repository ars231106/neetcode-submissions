#include <unordered_map>
#include <list>

class LRUCache {
private:
    int cap;
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        cache.splice(cache.end(), cache, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            cache.splice(cache.end(), cache, m[key]);
            m[key]->second = value;
            return;
        }
        if (cache.size() == cap) {
            m.erase(cache.front().first);
            cache.pop_front();
        }
        cache.push_back({key, value});
        m[key] = --cache.end();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */