class LFUCache {
    unordered_map<int, int> cache;
    unordered_map<int, pair<int, int>> counter;
    set<pair<int, pair<int, int>>> st;
    int cnt;
    int n;

public:
    LFUCache(int capacity) : cnt(0), n(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        auto temp = counter[key];
        cnt++;
        int freq = temp.first;
        int val = temp.second;
        st.erase({freq, {val, key}});
        st.insert({freq + 1, {cnt, key}});
        counter[key] = {freq + 1, cnt};
        return cache[key];
    }

    void put(int key, int value) {
        if (n == 0) return;

        if (cache.find(key) == cache.end() && cache.size() == n) {
            auto beg = st.begin();
            int keyVal = beg->second.second;
            cache.erase(keyVal);
            auto temp = counter[keyVal];
            st.erase(st.begin());
            counter.erase(keyVal);
        }
        cnt++;
        if (cache.find(key) != cache.end()) {
            auto temp = counter[key];
            int freq = temp.first;
            int val = temp.second;
            st.erase({freq, {val, key}});
            st.insert({freq + 1, {cnt, key}});
            counter[key] = {freq + 1, cnt};
        } else {
            st.insert({1, {cnt, key}});
            counter[key] = {1, cnt};
        }
        cache[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */