class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:nums){
            int val=it;
            if(mp.count(val-1)) continue;
            int cnt=0;
            while(mp.count(val)){
                cnt++;
                val++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};