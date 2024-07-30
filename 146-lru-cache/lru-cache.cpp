class LRUCache {
    int n;
    unordered_map<int, int> mp, counter;
    queue<int> q;

public:
    LRUCache(int capacity) { this->n = capacity; }

    int get(int key) {
        if (!counter.count(key)) {
            return -1;
        }
        counter[key]++;
        q.push(key);
        return mp[key];
    }

    void put(int key, int value) {
        mp[key] = value;
        counter[key]++;
        q.push(key);
        while (counter.size() > n) {
            int firstKey = q.front();
            q.pop();
            if (--counter[firstKey] == 0) {
                counter.erase(firstKey);
                mp.erase(firstKey);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */