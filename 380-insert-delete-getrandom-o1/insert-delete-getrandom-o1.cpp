class RandomizedSet {
public:
    unordered_map<int,int>mp;
    int index=0;
    vector<int>nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val]=nums.size();
        nums.push_back(val);
        index++;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int last=nums.back();
        mp[last]=mp[val];
        nums[mp[val]]=last;
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */