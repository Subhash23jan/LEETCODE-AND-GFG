class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mp;
        int ans=0;
        for(auto it:nums)
        {
            mp[it]++;
            ans+=(mp[it]-1);
        }
        return ans;
    }
};